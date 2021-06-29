#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); (i)++)
using namespace std;

void trace(int a[], int n) {
    rep(i,n) {
        cout << a[i];
        if (i < n-1)  cout << ' ';
        else  cout << '\n';
        }
}

void insertionSort(int a[], int n) {
    int v, j;
    for (int i = 1; i < n; i++) {
        v = a[i];
        j = i-1;
        while (j >= 0 && a[j] > v) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        trace(a,n);
    }
}

int main()
{
    int n;  cin >> n;
    int a[n];
    rep(i,n)  cin >> a[i];

    trace(a,n);
    insertionSort(a,n);
}
