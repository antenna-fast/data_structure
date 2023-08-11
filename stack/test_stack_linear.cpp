// Created by yaohua on 2022/5/1.
// array implementation of stack

#include <iostream>
#include <stdio.h>

using namespace std;


// OPERATIONS
// Push
int push(int *a, int top, int elem){
    top ++;
    a[top] = elem;
    cout << "top: " << top << endl;
    return top;
}

// Pop
int pop(int *a, int top){
    if (top == -1){
        cout << "ERROR: EMPTY STACK" << endl;
        return -1;
    }
    cout << "top: " << top << endl;
    top --;
    return top;
}

int main(){
    // init
    int a[100];
    int top = -1;

    // Push
    top = push(a, top, 100);
    top = push(a, top, 200);
    top = push(a, top, 999);

    // Pop
    top = pop(a, top);
    top = pop(a, top);
    top = pop(a, top);

    return 0;
}