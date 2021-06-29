#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); (i)++)
using namespace std;

int bubbleSort(int a[], int n) {
    int t, count = 0;
    bool flag = 1;
    while (flag) {
        flag = 0;
        for (int j = n-1; j > 0; j--) {
            if (a[j] < a[j-1]) {
                t = a[j];
                a[j] = a[j-1];
                a[j-1] = t;
                flag = 1;
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n, count = 0;  cin >> n;
    int a[n];
    rep(i,n)  cin >> a[i];

    count = bubbleSort(a,n);

    rep(i,n) {
        if (i < n-1)  cout << a[i] << ' ';
        else  cout << a[i] << endl;
    }
    cout << count << endl;
}
