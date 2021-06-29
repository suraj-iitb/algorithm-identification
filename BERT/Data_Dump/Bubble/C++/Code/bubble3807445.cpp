#include <bits/stdc++.h>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
int main() {
    int n;
    cin >> n;
    
    int x[n];
    rep(i, n) cin >> x[i];
    
    int flag = 1, tmp = 0, cnt = 0;
    while(flag) {
        flag = 0;
        for(int i=n-1; i > 0; i--) {
            if(x[i-1] > x[i]) {
                tmp = x[i-1];
                x[i-1] = x[i];
                x[i] = tmp;
                flag = 1;
                cnt++;
            }
        }

    }
    
    rep(i, n) cout << x[i] << ((i == n-1) ? "\n" : " ");
    cout << cnt << endl;
    
    
    
}
    

