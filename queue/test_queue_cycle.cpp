//
// Created by yaohua on 2022/5/2.
//
// Queue: First In First Out 
// array implementation of queue

#include <iostream>
#include <vector>
#include <string>

using namespace std;


// goal: serial data stream process
#define MAX_BUFFER_LENGTH 16
#define BUF_NO_DATA 0xFF 

#define CMD_LENGTH 8

uint8_t buffer[MAX_BUFFER_LENGTH];
uint8_t buffer_head = 0;
volatile uint8_t buffer_tail = 0;


// GRBL: 
//  it writ data to "head" pointer, when serial receive interrupt, head++
//  and read data using "tail" pointer, when read, tail++

// queue: []  idx: 0, SIZE-1
// internal structure: 
// old_data (tail), ......, new_data (head)

typedef struct Node
{
    uint8_t data_bytes[4];
    Node* next;
} Node;


uint8_t read_data()
{
    // copy volaile pointer to perform safity operation
    uint8_t tail = buffer_tail;

    if(buffer_head == tail)  // empty buffer
        return BUF_NO_DATA;
    else
    {
        uint8_t data = buffer[tail];
        // update tail pointer to prepare next read
        tail ++;
        if(tail == MAX_BUFFER_LENGTH)
            tail = 0;
        buffer_tail = tail;

        // data flow controller
        // if members in buffer lower than setting threshold, let upstream controller go ahead

        return data;
    }
} 

void rx_interrupt(uint8_t data)
{
    uint8_t data_tmp = data;

    uint8_t next_head = buffer_head + 1;
    if(next_head == MAX_BUFFER_LENGTH)
        next_head = 0;  // goto next buffer cycle

    buffer[buffer_head] = data_tmp;  // pack data to buffer

    // check head and tail
    // when < 0:
    // 0 -> -7 -> max -7
    // 1 -> -6 -> max -6
    // 6 -> -1 -> max -1
    // 7 -> 0
    int forward_idx = buffer_head - CMD_LENGTH + 1 >= 0 ?  buffer_head-CMD_LENGTH + 1 : buffer_head-CMD_LENGTH+1 + MAX_BUFFER_LENGTH;
    // int forward_idx = buffer_head - 7 >= 0 ?  buffer_head-7 : buffer_head- 7 + MAX_BUFFER_LENGTH;

    if(data_tmp == 0xFF && buffer[forward_idx] == 0xAA)
    {
        cout << "full cmd received: forward_idx: " << forward_idx << endl;

        for (size_t j = 0; j < CMD_LENGTH; j++)
        {
            cout << (int)buffer[(j + forward_idx) % MAX_BUFFER_LENGTH] << " ";
        }
        cout << endl;

        // process XONXOFF to avoid data overflow
    }

    buffer_head = next_head;

    // if(next_head != buffer_tail)  // make sure buffer not full (assume next_point occur tail as buffer full)
    // {
    //     buffer[buffer_head] = data_tmp;  // pack data to buffer
    //     buffer_head = next_head;  // update poitner to prepare next receive

    //     // data flow controller
    //     // if buffer is going to full, then call upstream to stop send
    // }

}

uint8_t get_buffer_count()
{
    return 1;
}

// // 进队列
// int push(int *a, int val, int rear)
// {
//     rear ++;
//     a[rear] = val;
//     return rear;
// }

// // 出队列
// int pop(int *a, int head, int rear)
// {
//     if (head == rear)
//     {
//         cout << "Empty Queue" << endl;
//         return -1;
//     }
//     head ++;
//     return head;
// }

int main()
{
    for (int i = 0; i < 32; i++)
    {
        if(i%8 == 0)
            rx_interrupt(0xAA);
        else if((i+1)%8 == 0)  // 0-7  8 bytes per line
            rx_interrupt(0xFF);
        else
            rx_interrupt(i);
    }
    

    return 0;
}