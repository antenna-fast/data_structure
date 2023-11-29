//
// Created by yaohua on 2022/5/2.
//
// Queue: First In First Out 
// linked implementation of queue
// 基于链表的实现:
// 我们可以将链表的“头节点”和“尾节点”分别视为“队首”和“队尾”，规定队尾仅可添加节点，队首仅可删除节点。
// ref: https://www.hello-algo.com/chapter_stack_and_queue/queue/#521

#include <iostream>

using namespace std;

typedef struct Node
{
    int val;
    Node* next;
} Node;


// 进队列
void push(Node* &queue, int val)
{
    Node* tmp = queue;  // move pointer to find the last node in linked-list
    
    if(!queue)
    {
        queue = new Node;
        queue->val = val;
        return;
    }

    while (tmp->next)  // find the last have value one
    {
        tmp = tmp->next;
    }
    
    Node* newNode = new Node;  // create new node
    newNode->val = val;

    tmp->next = newNode;  // insert at tail
}

// 出队列
int pop(Node* &queue)
{
    Node* tmp = queue;

    if(!tmp)
    {
        cout << "Empty Queue!" << endl;
        return -1;
    }

    Node* del = queue;
    int val = del->val;
    queue = queue->next;
    free(del);

    return val;
}


int main()
{
    // create queue using push
    Node* queue = nullptr;

    for (size_t i = 0; i < 5; i++)
    {
        push(queue, i);
    }

    for (size_t i = 0; i < 6; i++)
    {
        cout << pop(queue) << endl;
    }
    
    return 0;
}