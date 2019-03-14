// File Name: 7_1.cpp
// Author: JonnyOu
// Created Time: Thu 14 Mar 2019 10:39:18 AM CST

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool judge(int a, int b, int &p) {
   // cout << a << ' ' << b << endl;
    int t[10];
    memset(t, 0, sizeof(t));
    while (a != 0) {
        t[a%10]++;
        a /= 10;
    }
    while (b != 0) {
        t[b%10]++;
        b /= 10;
    }
    if (t[0] == 0)
        p = 1; //被除数和除数中都没有0,所以存在前导0
    if (t[0] > 1) 
        return false;
    for (int i = 1; i < 10; i++) //计算次数不等于1都不是我们要找的数
        if (t[i] != 1)
            return false;
    return true;
}

int main(){

    int n;

    cin >> n;

    //暴力循环
    for (int a = 0; a <= 9; a++) 
        for (int b = 0; b<=9; b++) 
                if (b != a) 
                    for (int c = 0; c <= 9; c++) 
                        if (c != a && c != b) 
                            for (int d = 0; d <= 9; d++) 
                                if (d != a && d != b && d != c)
                                    for (int e = 0; e <= 9; e++)
                                        if (e != a && e != b && e != c && e != d) {
                                            int sum = a*10000+b*1000+c*100+d*10+e; //获取除数
                                            int p = 0; //p判断是否存在前导0
                                            if (judge(sum*n,sum,p)) { //被除数
                                                if (p == 1)
                                                    printf("%d / %05d = %d\n", sum*n, sum, n);
                                                else 
                                                    printf("%d / %d = %d\n", sum*n, sum, n);
                                                    
                                            }
                                        }
    return 0;
}
