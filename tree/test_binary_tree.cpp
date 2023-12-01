// Created by yaohua on 2022/5/1.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct Node
{
    int val;  // 数据域
    Node* left; // 指针域
    Node* right;  
    Node(int val) : val(val), left(nullptr), right(nullptr) {}
} Node;


// 创建二叉树


// 遍历
// 1. 深度优先遍历, 它体现了一种“先走到尽头，再回溯继续”的遍历方式。
// 深度优先搜索通常基于递归实现

// 深度优先遍历分为三种: 
// 1.1 前序遍历：先访问当前节点，再依次递归访问左右子树。
// 1.2 中序遍历：先递归访问左子树，再访问自身，再递归访问右子树。
// 1.3 后序遍历：先递归访问左右子树，再访问自身节点。

// 前序遍历
// self-left-right
void preOrder(Node *root)
{
    if (root == nullptr)  // the end of branch comes
    {
        return;
    }
    cout << "val: " << root->val << endl;
    preOrder(root->left);
    preOrder(root->right);
}

// 中序遍历
// left-self-right
void midOrder(Node *root)
{
    if(root == nullptr)
    {
        return;
    }
    midOrder(root->left);
    cout << "mid: " << root->val << endl;;
    midOrder(root->right);
}

// 后序遍历
// left-right-self
void postOrder(Node* root)
{
    if(root == nullptr)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << "post: " << root->val << endl;
}


// 2. 层序遍历
// 「层序遍历 level-order traversal」从顶部到底部逐层遍历二叉树，并在每一层按照从左到右的顺序访问节点。
// 层序遍历本质上属于「广度优先遍历 breadth-first traversal」，它体现了一种“一圈一圈向外扩展”的逐层遍历方式。

// 广度优先遍历通常借助“队列”来实现。
// 队列遵循“先进先出”(Fist In First Out)的规则，而广度优先遍历则遵循“逐层推进”的规则，两者背后的思想是一致的。
// ref (good tutorial): https://www.runoob.com/data-structures/binary-search-level-traverse.html

void level_order_traversal(Node* tree)
{
    if(!tree)
    {
        cout << "Empty tree!" << endl;
        return;
    }
    // init queue
    Node* root = tree;
    queue<Node*> q;
    q.push(root);

    // operation
    while (!q.empty())
    {
        Node* tmp = q.front();
        q.pop();
        cout << tmp->val << endl;

        if(tmp->left)
        {
            q.push(tmp->left);
        }
        if(tmp->right)
        {
            q.push(tmp->right);
        }
    }
    return;
}

// 求树高

// 反转


int main()
{
    cout << "binary tree ... " << endl;

    // create binary tree
    Node* root = new Node(1);
    Node* child_1_l = new Node(2);
    Node* child_1_r = new Node(3);

    root->left = child_1_l;
    root->right = child_1_r;    

    Node* child_21_l = new Node(4);
    Node* child_21_r = new Node(5);
    Node* child_22_l = new Node(6);
    Node* child_22_r = new Node(7);

    child_1_l->left = child_21_l;
    child_1_l->right = child_21_r;

    child_1_r->left = child_22_l;
    child_1_r->right = child_22_r;
    
    // insert node
    // Node* insertNode = new Node(66);
    // root->left = insertNode;
    // insertNode->left = child_1_l;

    Node* tmp = root;   
    while (tmp)
    {
        cout << tmp->val << endl;
        tmp = tmp->left;
    }
    
    // level_order_traversal
    cout << "level_order_traversal: " << endl;
    level_order_traversal(root);

    // pre-order traversal
    cout << "pre-order traversal" << endl;
    preOrder(root);

    // mid-order
    cout << "mid-order traversal" << endl;
    midOrder(root);

    // post
    cout << "post " << endl;
    postOrder(root);

    return 0;
}
