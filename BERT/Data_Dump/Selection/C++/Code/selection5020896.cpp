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
    int minj,cnt=0;
    rep(i,n-1) {
        minj=i;
        for(int j=i; j<n; j++) {
            if(a[j]<a[minj]) {
                minj=j;
            }
        }
        if(a[i]>a[minj]) {
            swap(a[i],a[minj]);
            cnt++;
        }
    }
    rep(i,n) {
        if(i>0) cout << " ";
        cout << a[i];
    }
    cout << endl << cnt << endl;
    return 0;
}
