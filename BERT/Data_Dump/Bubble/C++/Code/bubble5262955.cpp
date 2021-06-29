#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
 
int main() {
    int n; cin >> n;
    int a[n];
    rep (i, n) cin >> a[i];
    
    bool flag = true;
    int count = 0;
    while (flag){
        flag = false;
        for (int j = n - 1; j > 0; j--){
            if (a[j] < a[j-1]){
                swap(a[j], a[j-1]);
                flag = true;
                count++;
            }            
        }
    }
    rep (i, n - 1) cout << a[i] << " ";
    cout << a[n - 1] << endl;
    cout << count << endl;
}
