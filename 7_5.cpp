// File Name: 7_5.cpp
// Author: JonnyOu
// Created Time: Thu 14 Mar 2019 09:28:52 PM CST

/*
 * 困难的串
 *
 */


#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int s[100];
int cnt = 0;
int n;
int L;

int dfs(int cur);

int main(){

    cin >> n >> L;
    dfs(0);

    return 0;
}

int dfs(int cur) {
    if (cnt++ == n) {
        for (int i = 0; i < cur; i++)
            printf("%c", 'A'+s[i]);
        cout << endl;
        return 0;
    }
    for (int i = 0; i < L; i++) {
        s[cur] = i;
        int ok = 1;
        for (int j = 1; j*2 <= cur+1; j++) {
            int equal = 1;
            for (int k = 0; k < j; k++) 
                if (s[cur-k] != s[cur-k-j]) {
                    equal = 0;
                    break;
                }
                if (equal) {
                    ok = 0;
                    break;
                }
        }
        if (ok)
            if (!dfs(cur+1)) 
                return 0;
    }
    return 1;
}
            
