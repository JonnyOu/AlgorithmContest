// File Name: 7_3.cpp
// Author: JonnyOu
// Created Time: Thu 14 Mar 2019 01:21:05 PM CST

#include <iostream>

using namespace std;

int a[10000][3];

int main(){

    int x, k, count = 0;

    cin >> k;
    for (int i = k+1; i <= 2*k; i++) {
        x = k*i/(i-k);
        if (x*(i-k) == (k*i)) {
            a[count][0] = k;
            a[count][1] = x;
            a[count++][2] = i;
        }     
    }
    cout << count << endl;
    for(int i = 0; i < count; i++)
        printf("1/%d = 1/%d + 1/%d\n", a[i][0], a[i][1], a[i][2]); 
    return 0;
}
