#include <bits/stdc++.h>
using namespace std;
int n,a[100005],cnt;

int main(){
    cin >> n;
    cnt = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        int t = i;
        bool check = false;
        for(int j = i; j < n; j++)
            if (a[t] > a[j]) {
                 t = j;
                 check = true;
            }
        if (check) cnt++;
        swap(a[i],a[t]);
    }
    for(int i = 0; i < n-1; i++) cout << a[i] << " ";
    cout << a[n-1];
    cout << '\n';
    cout << cnt << '\n';
}

