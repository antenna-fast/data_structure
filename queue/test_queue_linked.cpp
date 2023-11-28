//
// Created by yaohua on 2022/5/2.
//
// linked implementation of queue

#include <iostream>

using namespace std;


// 进队列
int enQueue(int *a, int val, int rear)
{
    rear ++;
    a[rear] = val;
    return rear;
}

// 出队列
int deQueue(int *a, int head, int rear)
{
    if (head == rear){
        cout << "Empty Queue" << endl;
        return -1;
    }
    head ++;
    return head;
}

int main(){

    return 0;
}