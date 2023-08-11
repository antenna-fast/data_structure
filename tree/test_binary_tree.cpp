// Created by yaohua on 2022/5/1.

#include <iostream>
#include <vector>

using namespace std;

// 孩子-兄弟表示法
typedef struct BiTNode{
    int value;  // 数据域
    BiTNode *lChild, *rChild;  // 指针域
} BiTNode;


// 创建二叉树
BiTNode * createTree(vector<int> a, int n){
    auto *root = new BiTNode;
    root -> value;
    root -> lChild = root -> rChild = nullptr;

    return root;
}

// 遍历
// 前序遍历
void preOrder(BiTNode *root){
    if (root == nullptr){
        return;
    }
    cout << "root: " << root -> value << endl;
    preOrder(root -> lChild);
    preOrder(root -> rChild);
}

// 中序遍历
void midOrder(BiTNode *root){
    if
}
// 后序遍历

// 层序遍历

// 求树高

// 反转


int main(){
    cout << "binary tree ... " << endl;
    BiTNode *root = nullptr;

    vector<int> a;
    for (int i = 0; i < 10; ++i) {
        a.emplace_back(i);
    }

    createTree();

    return 0;
}