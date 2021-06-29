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
int n, cnt;
vi s;
const int INF = INT_MAX;
void merge(int left, int mid, int right){
    int n1 = mid-left;
    int n2 = right-mid;
    vi L(n1+1), R(n2+1);
    REP(i,n1) L[i] = s[left + i];
    REP(i,n2) R[i] = s[mid  + i];
    L[n1] = INF;
    R[n2] = INF;

    {
        int i=0,j=0;
        FOR(k,left,right){
            if(L[i] <= R[j]){
                s[k] = L[i];
                i++;
            }else{
                s[k] = R[j];
                j++;
            }

            cnt++;
        }
    }
}

void mergeSort(int left, int right){
    if(left+1 < right){
        int mid = (left+right)/2;
        mergeSort(left, mid);
        mergeSort(mid, right);
        merge(left, mid , right);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    s.resize(n);
    REP(i,n) cin>>s[i];

    mergeSort(0, s.size());

    REP(i,n){
        cout<<s[i];
        if(i==n-1) cout<<endl;
        else cout<<" ";
    }
    cout << cnt << endl;
    return 0;
}
