// Author: Yaohua Liu
// date: 2023-12-01

#include <iostream>

using namespace std;


typedef struct Node
{
    int val;
    Node* next;
}Node;


void insert(Node* &head, int val)
{
    Node* tmp = head;
    while (tmp)
    {
        tmp = tmp->next;
    }
    Node* newNode = new Node;
    newNode->val = val;

    tmp = newNode;

    return;
}

int main(int argc, char** argv) 
{
    if(argc != 1)
    {
        std::cout << " argc not match, Usage: " << std::endl;
        return -1;
    }

    std::cout << "running: " << argv[0] << std::endl;

    Node* a = nullptr;

    for (size_t i = 0; i < 5; i++)
    {
        insert(a, i);
    }
    
    Node* tmp = a;
    while (tmp)
    {
        cout << tmp->val << endl; 
        tmp = tmp ->next;
    }
    
    return 0;
}