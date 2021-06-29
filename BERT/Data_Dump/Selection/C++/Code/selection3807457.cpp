#include <bits/stdc++.h>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
int main() {
    int n;
    cin >> n;
    
    int x[n];
    rep(i, n) cin >> x[i];
    
    int minj ,tmp = 0, cnt = 0;
    for(int i = 0; i < n; i++) {
        minj = i;
        for(int j = i; j < n; j++) {
            if(x[minj] > x[j]) {
                minj = j;
            }
        }
        if(minj != i)
        {
            tmp = x[i];
            x[i] = x[minj];
            x[minj] = tmp;
            cnt++;
        }
    }
    
    
    rep(i, n) cout << x[i] << ((i == n-1) ? "\n" : " ");
    cout << cnt << endl;
    
    
    
}
    

