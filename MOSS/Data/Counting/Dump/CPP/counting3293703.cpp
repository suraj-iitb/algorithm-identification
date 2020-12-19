#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int a[n];
    int Max = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        Max = (Max < a[i]) ? a[i] : Max;
    }
    typedef long long ll;
    ll c[Max + 1];
    for (int i = 0; i <= Max; i++) {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        c[a[i]]++;
    }/*
    for (int i = 0; i <= Max; i++) {
        cout << c[i] << " ";
    }
    cout << endl;*/
    for (int i = 1; i <= Max; i++) {
        c[i] += c[i - 1];
    }
    for (int i = 0; i <= Max; i++) {
        c[i]--; //0 start
    }/*
    for (int i = 0; i <= Max; i++) {
        cout << c[i] << " ";
    }
    cout << endl;*/
    int b[n];
    for (int i = n - 1; i >= 0; i--) {
        b[c[a[i]]] = a[i]; //a[i]はcountされた番目にいく
        c[a[i]]--; //次同じ数来たら
    }
    for (int i = 0; i < n; i++) {
        if (i) {
            cout << " ";
        }
        cout << b[i];
    }
    cout << endl;
}

