//
// Created by yaohua on 2022/5/2.
//
// Queue: First In First Out 
// array implementation of queue

#include <iostream>

using namespace std;


// 进队列
int push(int *a, int val, int rear)
{
    rear ++;
    a[rear] = val;
    return rear;
}

// 出队列
int pop(int *a, int head, int rear)
{
    if (head == rear)
    {
        cout << "Empty Queue" << endl;
        return -1;
    }
    head ++;
    return head;
}

int main(){

    return 0;
}