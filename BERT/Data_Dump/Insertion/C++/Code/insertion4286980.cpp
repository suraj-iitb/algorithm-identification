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

//挿入ソート
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin>>n;
    int a[101]={};
    REP(i,n) cin>>a[i];

    REP(j,n){
        cout<<a[j];
        if(j<n-1) cout<<" ";
        else cout<<endl;
    }

    //            []
    //[][][][][][]
    //  []<<すいー
    //[]>>[][][[][][]
    FOR(i,1,n){
        int tmp = a[i];
        int pos = i-1;
        while(pos>=0 && a[pos]>tmp){
            a[pos+1] = a[pos];
            pos--;
        }
        a[pos+1]=tmp;
        
        REP(j,n){
            cout<<a[j];
            if(j<n-1) cout<<" ";
            else cout<<endl;
        }
    }
    return 0;
}
