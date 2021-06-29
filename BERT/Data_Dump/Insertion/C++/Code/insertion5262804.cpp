#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
 
int main() {
    int n; cin >> n;
    int a[n];
    rep (i, n) cin >> a[i];
    
    rep (x, n) 
        if (x != n - 1)
            cout  << a[x] << " ";
        else
            cout << a[n - 1] << endl;
    
    for (int i = 1; i < n; i++){
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] >= v){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = v;
        
        rep (x, n) 
            if (x != n - 1)
                cout  << a[x] << " ";
            else
                cout << a[n - 1] << endl;
    }

}
