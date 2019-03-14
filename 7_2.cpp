// File Name: 7_2.cpp
// Author: JonnyOu
// Created Time: Thu 14 Mar 2019 01:08:28 PM CST

#include <iostream>

using namespace std;
using LL = long long;

int main(){

    LL sum = 1, note = 1;
    int n, a[20];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            note = 1;
            for (int k = i; k <= j; k++) 
                note *= a[k];
            if (sum < note) 
                sum = note;
        }
    }
    if (sum < 0)
        cout << 0 << endl;
    else 
        cout << sum << endl;

    return 0;
}
