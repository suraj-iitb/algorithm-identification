#include <bits/stdc++.h>
using namespace std;
int n,a[100005],cnt;

int main(){
    cin >> n;
    cnt = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        for(int j = n-1; j >= i+1; j--)
            if (a[j] < a[j-1]) {
                cnt++;
                swap(a[j],a[j-1]);
            }
    }
    for(int i = 0; i < n-1; i++) cout << a[i] << " ";
    cout << a[n-1];
    cout << '\n';
    cout << cnt << '\n';
}

