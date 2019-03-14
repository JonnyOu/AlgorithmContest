// File Name: 7.2.1.cpp
// Author: JonnyOu
// Created Time: Thu 14 Mar 2019 02:09:31 PM CST

/*
 * 求一个自定义数组的全排列
 *
 * 递归
 *
 */

#include <iostream>
using namespace std;

void print_permutation(int n, int *a, int *p, int cnt);

int main(){
    
    int n = 3;
    int a[3], p[3] = {1,2,3};
    
    print_permutation(n, a, p, 0);

    return 0;
}

void print_permutation(int n, int *a, int *p,  int cnt) {
    if (cnt == n) {
        for (int i = 0; i < n; i++)
            cout << a[i];
        cout << endl;
    }
    else 
        for (int i = 0; i < n; i++) {
            if (!i || p[i] != p[i-1]) {
                int c1 = 0, c2 = 0;
                for (int j = 0; j < n; j++)    
                    if (p[j] == p[i]) 
                        c1++;
                for (int j = 0; j < cnt; j++)
                    if (a[j] == p[i])
                        c2++;
                if (c1 > c2) {
                    a[cnt] = p[i];
                    print_permutation(n, a, p, cnt+1);
                }
            }
        }
}

