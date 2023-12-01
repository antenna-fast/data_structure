#include <iostream>

using namespace std;

typedef struct Node
{
    int val;
    Node* next;

    Node(int val) : val(val), next(nullptr) {}
}Node;


int main()
{

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);

    node1->next = node2;
    node2->next = node1;  // tail's rail link to head, build a circle

    Node* tmp = node1;
    int idx=0;
    while (idx<20 && tmp)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
        idx++;
    }

    cout << "....." << endl;

    // merge two circle linked-list
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node3->next = node4;
    node4->next = node3;  // tail's rail link to head, build a circle

    node2->next = node3;
    node4->next = node1;

    tmp = node1;
    idx=0;
    while (idx<20 && tmp)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
        idx++;
    }

    return 0;
}