// Created by yaohua on 2022/5/2.
// 链式栈
// 将链表的head作为栈顶，tail作为栈底，可以实现快速操作

#include <iostream>

using namespace std;


typedef struct Node{
    int val;
    Node *next;
} Node;

// Push
Node * Push(Node *t_head, int value){
    // create a new node
    Node *newNode = new Node;
    newNode -> val = value;
    // insert newNode as new head
    newNode->next = t_head;

    return newNode;  // update head
}

// Pop
Node * Pop(Node *t_head){
    if (!t_head){
        cout << "Empty Stack!" << endl;
        return t_head;
    }

    Node *del = t_head;  // buffer head for delete
    t_head = t_head -> next;  // skip head
    free(del);
    if (t_head){
        cout << "head value is: " << t_head->val << endl;
    } else{
        cout << "Stack Cleared!" << endl;
    }
    return t_head;
}

int main(){
    Node *List = new Node;

    return 0;
}