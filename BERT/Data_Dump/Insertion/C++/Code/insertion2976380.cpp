#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)cin>>a[i];
    for (int i = 1; i < n; ++i) {
        int v = a[i];
        int j = i - 1;
        for (int k = 0; k < n-1; ++k) {
            cout << a[k]<<" ";
        }
        cout << a[n-1]<<endl;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            a[j] = v;
            --j;
        }
    }
    for (int k = 0; k < n-1; ++k) {
        cout << a[k]<<" ";
    }
    cout << a[n-1]<<endl;
    return 0;
}
