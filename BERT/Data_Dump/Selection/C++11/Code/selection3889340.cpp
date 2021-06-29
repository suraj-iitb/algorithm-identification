#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); (i)++)
using namespace std;

int selectionSort(int a[], int n) {
    int t, minj, count = 0;
    rep(i,n) {
        minj = i;
        for (int j = i; j < n; j++)
            if (a[j] < a[minj])  minj = j;
        t = a[i];  a[i] = a[minj];  a[minj] = t;
        if (i != minj)  count++;
    }
    return count;
}

int main() {
    int n, count;  cin >> n;
    int a[n];
    rep(i,n)  cin >> a[i];

    count = selectionSort(a,n);

    rep(i,n) {
        if (i < n-1)  cout << a[i] << ' ';
        else  cout << a[i] << endl;
    }
    cout << count << endl;
}
