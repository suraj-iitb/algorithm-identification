#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, cnt = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
    }
    bool flag = true;
    while (flag){
        flag = false;
        for (int i = n - 1; i > 0; --i){
            if (a[i] < a[i - 1]){
                swap(a[i], a[i - 1]);
                flag = true;
                ++cnt;
            }
        }
    }
    for (int i = 0; i < n - 1; ++i){
        cout << a[i] << ' ';
    }
    cout << a[n-1] << endl;
    cout << cnt << endl;
    return 0;
}
