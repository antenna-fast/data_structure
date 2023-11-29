// Created by yaohua on 2022/5/2.
// stack: first in last out, last in first out
// 链式栈
// 将链表的head作为栈顶，tail作为栈底，可以实现快速操作
// push: input
// pop: output

#include <iostream>

using namespace std;


typedef struct Node
{
    int val;
    Node *next;
} Node;

// Push
Node* Push(Node* &t_head, int value)
{
    // create a new node
    Node *newNode = new Node;
    newNode->val = value;

    // insert newNode as new head
    newNode->next = t_head;
    t_head = newNode;

    return newNode;  // update head
}

// Pop
int Pop(Node* &t_head)
{
    if (!t_head)
    {
        cout << "Empty Stack!" << endl;
        return -1;
    }

    Node *del = t_head;       // buffer head for delete
    int val = del->val;

    t_head = t_head -> next;  // update head
    free(del);

    return val;
}

int main()
{
    Node *stack = nullptr;

    // create stack using push 
    for (size_t i = 0; i < 5; i++)
    {
        Push(stack, i);
    }

    for (size_t i = 0; i < 6; i++)
    {
        int val = Pop(stack);
        cout << "pop: " << val << endl;
    }
    

    return 0;
}