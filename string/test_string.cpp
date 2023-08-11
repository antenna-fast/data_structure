//
// Created by yaohua on 2022/5/2.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using namespace std;


// BF

// KMP


int main(){
    // 静态数组表示
    char var_str[4] = "123";  // char的长度至少为len(str)+1, 最后一位保存"/0"

    // 堆内存 / 动态数组
    char *str_var_1;
    char *str_var_2;
    str_var_1 = (char *)malloc(10 * sizeof(char));
    strcpy(str_var_1, "1234");

    str_var_2 = (char *)malloc(10 * sizeof(char));
    strcpy(str_var_2, "5678");

    int length_1 = strlen(str_var_1);
    int length_2 = strlen(str_var_2);
    cout << "length_1: " << length_1 << endl;
    cout << "length_2: " << length_2 << endl;

    if (length_1 + length_2 > 10){
        str_var_1 = (char*)realloc(str_var_1, (length_1 + length_2 + 1) * sizeof(char));
    }

    // 将str2合并到str1
    for (int i = length_1; i < length_1 + length_2; ++i) {
        str_var_1[i] = str_var_2[i - length_1];
    }
    str_var_1[length_1 + length_2] = '\0';

    free(str_var_1);
    free(str_var_2);

    return 0;
}