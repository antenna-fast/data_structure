#include <iostream>

using namespace std;

typedef struct Node 
{
    int val;
    Node *next;
} Node;


void insertNode(Node* &head, int idx, int val)
{
    // if insert at 1
    if(idx == 1)
    {
        Node* n = new Node();
        n->val = val;
        
        n->next = head;
        // cout << "after head->next" << endl;
        head = n; 
    }
    else  // insert at other position
    {
        Node *tmp = head;
        int posi = 1;
        while (posi < idx-1)  // get insert position's prior
        {
            posi ++;  // do NOT forget!
            tmp = tmp->next;
            if(tmp == nullptr)
            {
                cout << "overlength" <<endl;
                return;
            }
        }
        Node* node = new(Node);
        node->val = val;
        
        node->next = tmp->next;
        tmp->next = node;
    }

    return;
}

int main()
{
    // create a linked list

    Node *list = nullptr;
    // Node *list = new Node;

    for (size_t i = 1; i < 3; i++)
    {
        cout << "insert" << endl;
        // list = insertNode(list, i, i);
        insertNode(list, i, i);
    }
    
    
    Node *tmp = list;
    while (tmp)
    {
        cout << "tmp: " << tmp->val << endl;
        tmp = tmp->next;
    }
    
    return 0;
}