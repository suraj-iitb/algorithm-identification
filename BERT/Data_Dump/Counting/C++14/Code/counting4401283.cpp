#include<bits/stdc++.h>
#include<iostream>
using namespace std;
typedef long long ll;

#define MAX 2000005
#define VAL_MAX 10005

int main(int, char**)
{
    int n;
    cin >> n;

    int a[MAX];
    int b[MAX];
    int c[VAL_MAX] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
        c[a[i]]++;

    for (int i = 1; i < VAL_MAX; i++)
        c[i] += c[i-1];

    for (int i = n-1; i >= 0; i--) {
        b[c[a[i]]] = a[i];
        c[a[i]]--;
    }

    for (int i = 1; i < n; i++)
        cout << b[i] << " ";
    cout << b[n] << endl;

    return 0;
}
