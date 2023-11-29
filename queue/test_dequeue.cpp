//「双向队列 double-ended queue」提供了更高的灵活性，允许在头部和尾部执行元素的添加或删除操作
// ref: https://www.hello-algo.com/chapter_stack_and_queue/deque/

// TODO: use bi-direction linked-list

#include <iostream>

using namespace std;

typedef struct Node
{
    int val;
    Node* next;
}Node;


int pop_first(Node* &dequeue)
{
    Node* tmp = dequeue;
    if(!tmp)
    {
        cout << "Empty dequeue!" << endl;
        return -1;
    }

    Node* del = dequeue;
    int val = del->val;
    dequeue = dequeue->next;
    free(del);

    return val;
}

int pop_last(Node* &dequeue)
{
    if(!dequeue)
    {
        cout << "Empty dequeue!" << endl;
        return -1;
    }

    Node* tmp = dequeue;
    while (tmp->next)
    {
        tmp = tmp->next;
    }
    
}

void push_first()
{

}

void push_last()
{

}

int main()
{

    return 0;
}
