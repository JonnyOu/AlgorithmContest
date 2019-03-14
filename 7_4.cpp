// File Name: 7_4.cpp
// Author: JonnyOu
// Created Time: Thu 14 Mar 2019 08:41:07 PM CST

/*
 * 素数环
 *
 */

#include <iostream>
#include <cstring>
using namespace std;

int n;
int tot = 0;
int a[20];
int isp[50];
int visit[50];

void dfs(int);
bool is_prime(int);

int main(){
   
    cin >> n;
    for (int i = 2; i <= n*2; i++)
        if (is_prime(i))
            isp[i] = 1;
    a[0] = 1;
    dfs(1);

    return 0;
}

void dfs(int cur) {
    if (cur == n && isp[a[n-1]+a[0]]) {
        for (int i = 0; i < n; i++) 
            cout << a[i] << ' ';
        cout << endl;
        tot++;
    }
    else 
        for (int i = 2; i <= n; i++) {
            if (!visit[i] && isp[i+a[cur-1]]) {
                a[cur] = i;
                visit[i] = 1;
                dfs(cur+1);
                visit[i] = 0;
            }
        }
}

bool is_prime(int n) {
    if (n == 2)
        return true;
    for (int i = 2; i*i <= n; i++) 
        if (n % i == 0)
            return false;
    return true;
}


