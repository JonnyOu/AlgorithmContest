// File Name: 7.2.1.cpp
// Author: JonnyOu
// Created Time: Thu 14 Mar 2019 02:09:31 PM CST

/*
 * 求一个序列的全排列
 *
 * 方法1.递归
 * 方法2.利用next_permutation函数
 *
 */

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void print_permutation(int n, int *a, int cnt);
void permutation(string str);

int main(){
    
    int n = 3;
    int a[n] = {1,2,3};
    string str = "123";

    cout << "方法1:" << endl;
    print_permutation(n, a, 0);

    cout << "方法2:" << endl;
    permutation(str);

    return 0;
}

void print_permutation(int n, int *a, int cnt) {
    if (cnt == n) {
        for (int i = 0; i < n; i++)
            cout << a[i];
        cout << endl;
    }
    else 
        for (int i = 1; i <= n; i++) {
            int note = 1;
            for (int j = 0; j < cnt; j++) {
                if (a[j] == i) 
                    note = 0;
            }
            if (note == 1) {
                a[cnt] = i;
                print_permutation(n, a, cnt+1);
            }
        }
}

void permutation(string str) {
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}
