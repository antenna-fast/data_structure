// Author: Liu Yaohua
// date: 2024-10-21

#include <iostream>

using namespace std;


typedef struct Node 
{
    int val;
    Node *next;
} Node;


void print_linked(Node* head)
{
  while (head)
  {
    std::cout << head->val << std::endl;
    head = head->next;
  }

  // Node* tmp = head;
  // while (tmp)
  // {
  //   std::cout << tmp->val << std::endl;
  //   tmp = tmp->next;
  // }
}

int main(int argc, char** argv) 
{
  if(argc != 1)
  {
    std::cout << " argc not match, Usage: " << std::endl;
    return -1;
  }
 
  // std::cout << "running: " << argv[0] << std::endl;
  
  // create a linked list
  Node* head = nullptr;
  for (int i = 0; i< 5; i++)
  {
    Node* new_node = new Node;
    new_node->val = i;

    // insert at head
    new_node->next = head;
    head = new_node;
  }

  // print_linked(head);

  print_linked(head);

  // if delete the first one
  // head = head->next;
  // std::cout << "after delete" << std::endl;
  // print_linked(head);

  int cnt = 0;
  Node* tmp = head;
  Node* tmp_next = tmp->next;

  int del_idx = 1;  // start from 0
  
  // if del_idx >= 1, using this
  while (cnt < del_idx - 1)
  {
    tmp = tmp->next;
    tmp_next = tmp->next;
    cnt++;
    std::cout << "cnt: " << cnt << std::endl;
  }

  tmp->next = tmp_next->next;

  print_linked(head);

  return 0;
}
