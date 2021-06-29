#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG2(x,y) cout<<#x<<": "<<x<<" "<<#y<<": "<<y<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    int a[101]={};
    REP(i,n) cin>>a[i];
    int cnt=0;

    //選択ソート
    REP(i,n){
        int mn=i;
        FOR(j,i,n){
            if(a[j]<a[mn]) mn=j;
        }

        if(i!=mn){
            swap(a[i], a[mn]);
            cnt++;
        }
    }

    REP(i,n){
        cout<<a[i];
        if(i==n-1) cout<<endl;
        else cout<<" ";
    }
    cout << cnt << endl;
    return 0;
}
