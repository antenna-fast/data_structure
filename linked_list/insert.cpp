typedef struct Node 
{
    int val;
    Node *next;
} Node;


Node* insertNode(Node *head, int idx, int val)
{
    // if insert at 1
    if(idx == 1)
    {
        Node* n = new Node;
        n->val = val;
        
        n->next = head->next;
        head = n;
        return head;
    }
    
    // insert at other position

    return head;
}

int main()
{
    // create a linked list

    return 0;
}