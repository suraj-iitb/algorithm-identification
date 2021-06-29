#include <bits/stdc++.h>
using namespace std;
int n,a[100005];
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        int tmp = a[i];
        int j = i-1;
        while (j >= 0 && a[j] > tmp) {
            a[j+1] = a[j--];
        }
        a[j+1]=tmp;
        for(int i = 0; i < n-1; i++)
            cout << a[i] << " ";
        cout << a[n-1] << '\n';
    }
}

