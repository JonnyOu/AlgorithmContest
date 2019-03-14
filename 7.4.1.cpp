// File Name: 7.4.1.cpp
// Author: JonnyOu
// Created Time: Thu 14 Mar 2019 06:59:46 PM CST

/*
 * 八皇后问题 回溯法
 * 
 *
 */

#include <iostream>

using namespace std;

int n = 8;
int tot = 0;
int a[8];

void search(int cur);
void search2();
bool check(int k);

int main(){
    
    //cout << tot << endl;
    //search(0);
    //cout << tot << endl;

    search2();    
    cout << tot << endl;

    return 0;
}

void search(int cur) {
    if (cur == n) {
        for (int i = 0; i < n; i++) 
            cout << a[i] << ' ';
        cout << endl;
        tot++;
    }
    else 
        for (int i = 0; i < n; i++) {
            int note = 1;
            a[cur] = i;
            for (int j = 0; j < cur; j++) {
                if (a[cur] == a[j] || cur-a[cur] == j-a[j] || cur+a[cur] == j+a[j]) {
                    note = 0;
                    break;
                }
            }
            if (note)
                search(cur+1);
        }
}

void search2() {
    int cur = 0;
    a[cur] = -1;
    while (cur >= 0) {
        a[cur]++;
        while (a[cur]<n && !check(cur))
            a[cur]++;
        if (a[cur] < n) {
            if (cur+1 == n) {
                for (int j = 0; j <= cur; j++) 
                    cout << a[j] << ' ';
                cout << endl;
                tot++;
            }
            else 
                a[++cur] = -1;
        }
        else 
            cur--;
    }
}

bool check(int cur) {
    for (int j = 0; j < cur; j++) 
            if (a[cur] == a[j] || cur-a[cur] == j-a[j] || cur+a[cur] == j+a[j]) 
                return false;
   return true;
}




        

