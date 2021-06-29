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
    bool flag=1;
    int cnt=0;
    while (flag) {
        flag=0;
        for(int i=n-1; i>=1; i--) {
            if(a[i]<a[i-1]) {
                int tmp;
                tmp=a[i];
                a[i]=a[i-1];
                a[i-1]=tmp;
                cnt++;
                flag=1;
            }
        }
    }
    rep(i,n) {
        if(i>0) cout << " ";
        cout << a[i];
    }
    cout << endl << cnt << endl;
    return 0;
}
