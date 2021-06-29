#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define INF ((1LL<<62)-(1LL<<31))
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int a[n+1];
    rep(i,n) cin >> a[i];
    rep(i,n) {
        if(i>0) cout << " ";
        cout << a[i];
    }
    cout << endl; 
    for(int i=1; i<n; i++) {
        int v=a[i];
        int j=i-1;
        while(j>=0&&a[j]>v) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=v;
        rep(i,n) {
            if(i>0) cout << " ";
            cout << a[i];
        }
        cout << endl; 
    }
    return 0;
}
