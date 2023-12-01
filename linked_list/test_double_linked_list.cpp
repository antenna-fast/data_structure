// 双向链表
// 与单向链表相比，双向链表记录了两个方向的引用。
// 双向链表的节点定义同时包含指向后继节点（下一个节点）和前驱节点（上一个节点）的引用（指针）。
// 相较于单向链表，双向链表更具灵活性，可以朝两个方向遍历链表，但相应地也需要占用更多的内存空间。
// ref: https://www.hello-algo.com/chapter_array_and_linkedlist/linked_list/#422-vs

#include <iostream>

using namespace std;


// define Node structure
typedef struct Node
{
    int val;
    Node *prev;
    Node *next;

    Node(int val): val(val), prev(nullptr), next(nullptr) {}
} Node;


void insertNode(Node* &list, int posi, int val)
{
    if(posi < 1)
    {
        cout << "underlength" << endl;
        return;
    }

    if(posi == 1)
    {
        if(list == nullptr)
        {
            Node* newNode = new Node(val);
            list = newNode;
        }
        else
        {
            Node *newNode = new Node(val);
            newNode->next = list;  // insert
            list->prev = newNode;
            list = newNode;        // update list
        }
    }
    else
    {
        Node* tmp = list;
        // find insert position's previous one
        int idx = 1;
        while (idx < posi-1)
        {
            tmp = tmp->next;
            if(tmp == nullptr)
            {
                cout << "overlength" << endl;
                return;
            }

            idx ++;
        }
        
        Node *newNode = new Node(val);
        newNode->next = tmp->next;
        newNode->prev = tmp;
        if(tmp->next)  // if insert position not at tail
        {
            tmp->next->prev = newNode;
        }
        tmp->next = newNode;
    }

    return;
}

int deleteNode(Node* &list, int posi)
{
    if(list == nullptr)
    {
        cout << "Empty list!" << endl;
        return -1;
    }

    if(posi == 1)
    {
        Node* del = list;
        int val = del->val;
        list = list->next;
        free(del);
        return val;
    }
    else
    {
        Node* tmp = list;
        // find prior node at del position
        int idx=1;
        while (idx < posi-1)
        {
            tmp = tmp->next;
            if(tmp->next == nullptr)
            {
                cout << "overlength!" << endl;
                return -1;
            }
            idx ++;
        }

        Node* del = tmp->next;
        int val = del->val;
        tmp->next = del->next;
        if(del->next)  // if del not at tail
        {
            del->next->prev = tmp;
        }
        free(del);

        return val;
    }

}

int main()
{
    Node* list = nullptr;
    // Node* list = new Node(0);

    for (size_t i = 1; i < 5; i++)
    {
        cout << "insert" << endl;
        insertNode(list, i, i);
    }

    Node* tmp = list;    
    while (tmp)
    {
        cout << "tmp: " << tmp->val << endl;
        tmp = tmp->next;        
    }
    
    for (size_t i = 1; i < 5; i++)
    {
        cout << "del: " << deleteNode(list, 1) << endl;
    }
    
    
    return 0;
}