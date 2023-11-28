//
// Created by yaohua on 2022/4/30.
//

#include <iostream>
#include <cstdlib>

using namespace std;

// 单向链表

// define a Node
typedef struct Node
{
    int value;
    Node *next;  // 包含对自身引用的类型，称作自引用数据类型或自引用数据结构
} Node;


// Operations
// Init 构造一个空的线性表

// Destroy TODO
bool destroyList(Node *head)
{
    Node *p = head;
    Node *pr = nullptr;

    while (p)
    {
        pr = p;  // 保存当前结点
        p = p -> next;  // 更新游走指针
        free(pr);  // 删除当前的结点
    }
    free(p);

    return true;
}

// 插入(没有头结点的情况)
Node *insertElem(Node *head, int i, int value)
{
    Node *tmp = head;  // 游走的指针

    // 第一个位置插入
    if (i == 1)
    {
        // 创建结点
        Node *newNode = new Node;
        newNode -> value = value;
        // 插入
        newNode -> next = head;
        head = newNode;  // update head address
        return head;
    }

    // 其他位置插入
    else 
    {
        // find node(i-1)
        // for example, if i == 2, not move tmp, and tmp still is head (node1)
        // if i == 3, move tmp one step, and tmp is node2
        for (int j = 1; j < i - 1; ++j)
        {
            // 判断是否越界
            if(tmp == nullptr)
            {
                cout << "out of index!" << endl;
                return head;
            }
            tmp = tmp->next;  // move tmp
        }

        // 创建新的node
        Node *newNode = new Node;
        newNode->value = value;
        // 插入
        newNode->next = tmp->next;  // tail part
        tmp->next = newNode;
        return head;
    }
}


// 删除位置i的元素
Node * deleteElem(Node *head, int i)
{
    Node *tmp = head;

    // 删除第一个
    if (i == 1)
    {
        Node *del = tmp;  // 保存要删除的结点
        tmp = tmp->next;  // 执行跳转
        free(del);  // 释放删除结点的内存
        return tmp;
    }

    else
    {
        // 找到前驱结点(i-1) tmp
        int counter = 1;
        while (counter < i - 1)
        {
            counter ++;
            tmp = tmp -> next;
        }
        Node *del = tmp -> next;  // del buffer
        tmp -> next = tmp -> next -> next;
        free(del);
        return head;
    }
}

// 链表长度
bool ListLength(Node *p, int &length)
{
    Node *tmp = p;
    length = 0;
    while (tmp)
    {
        length += 1;
        tmp = tmp -> next;
    }
    return true;
}

// 遍历链表
void displayList(Node *p)
{
    Node *tmp = p;
    int idx = 0;
    while (tmp)
    {
        cout << "idx: " << idx << " value: " << tmp->value << endl;
        tmp = tmp->next;
        idx ++;
    }
}

// Compare

// High Level Operation

// eg 2.1
// A = A \cup B
void UnioxList(){

}

// eg 2.2
// 合并有序链表

// 反转链表


// 双向链表

// define a Node
typedef struct BiNode
{
    int value;
    BiNode *last;
    BiNode *next;
} BiNode;


// 循环链表


int main()
{
    // 创建一个链表
    Node *head = nullptr;  // 创建头指针(NULL)

    // 创建首结点
    Node *firstNode = new Node;
    firstNode->value=12;  // 存储值
    firstNode->next = nullptr;  // 链表的结尾

    // 将第一个结点的地址赋予head指针
    head = firstNode;

    // 创建第二个节点
    Node *secondNode = new Node;
    secondNode->value=123;
    secondNode->next = nullptr;
    
    // 第一个结点指向第二个结点
    firstNode->next = secondNode; 

    cout << "head: " << head->value << endl;
    cout << "head->next: " << head->next->value << endl;

    // init tmp node
    Node *tmpNode = secondNode;

    for (int i = 0; i < 5; ++i)
    {
        Node *newNode = new Node;  // 创建结点
        newNode->value = i;
        newNode->next = nullptr;

        tmpNode->next = newNode;
        tmpNode = newNode;  // update tmp node
    }

    head = insertElem(head, 2, 999);
//    cout << "insert state: " << state << endl;

    // 遍历list
    displayList(head);

    // List长度
    int length = 0;
    ListLength(head, length);
    cout << "length: " << length << endl;

    head = deleteElem(head, 3);
    // 遍历list
    displayList(head);
    ListLength(head, length);
    cout << "length: " << length << endl;

    cout << "destroy list .. " << endl;
    destroyList(head);
    // 遍历list
    displayList(head);
    ListLength(head, length);
    cout << "length: " << length << endl;

    Node *tp_1 = new Node;
    tp_1 -> value = 100;

    Node *tp_2 = new Node;
    tp_2 -> value = 888;

    Node *tp_3 = tp_1;
    tp_3 = tp_2;

    cout << tp_1-> value << endl;

    tp_2 -> next = tp_1;

    return 0;
}