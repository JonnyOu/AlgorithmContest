// File Name: 7.3.1.cpp
// Author: JonnyOu
// Created Time: Thu 14 Mar 2019 03:13:45 PM CST

/*
 * 给定一个集合,枚举所有可能的子集
 *
 * 1.增量构造法
 * 2.位向量法
 * 3.二进制法
 *
 */

#include <iostream>

using namespace std;

void print_subset_1(int n, int *a, int cur);
void print_subset_2(int n, int *b, int cur);
void print_subset_3(int n, int s);

int main(){
    int n = 3;
    int a[3] = {1,2,3};
    print_subset_1(n, a, 0);
    cout << endl; 
    
    for (int i = 0; i < (1<<n); i++)
        print_subset_3(n,i);

    return 0;
}

void print_subset_1(int n, int *a, int cur) {
    for (int i = 0; i < cur; i++)
        cout << a[i];
    cout << endl;
    int s = cur ? a[cur-1]+1 : 0; //集合排列由小到大且元素不重复
    for (int i = s; i < n; i++) {
        a[cur] = i;
        print_subset_1(n, a, cur+1);
    }
}

void print_subset_2(int n, int *b, int cur) {
    if (cur == n) {
        for (int i = 0; i < cur; i++)
            if (b[i])
                cout << i;
        cout << endl;
        return ;
    }
    b[cur] = 1;
    print_subset_2(n, b, cur+1);
    b[cur] = 0;
    print_subset_2(n, b, cur+1);
}

void print_subset_3(int n, int s) {
    for (int i = 0; i < n; i++)
        if (s&(1<<i))
            cout << i << ' ';
    cout << endl;
}
