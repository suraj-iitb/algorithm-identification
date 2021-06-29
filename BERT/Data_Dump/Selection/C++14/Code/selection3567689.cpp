#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
using pll = pair<ll, ll>;
using vp = vector<pll>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repb(i, n) for (int i = (n-1); i >= 0; i--)
#define rea(i, a, b) for (int i = (a); i < (b); i++)
#define reab(i, a, b) for (int i = (a)-1; i >= (b); i--)
#define ALL(a) (a).begin(),(a).end()
#define SZ(x) ((int)(x).size())
#define PRINT(V) for (auto v:(V)) {cerr << v << " ";} cerr << endl
#define dump(x) cerr << #x << " : " << (x) << endl
#define dump2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")" << endl
inline ll GCD(ll a, ll b){return b ? GCD(b, a % b) : a;}
const int MOD = 1000000007;
/* END OF TEMPLATE */

int selectionSort(vi& A, int N){
    int c = 0;
    rep(i, N){
        int minj = i;
        rea(j, i, N){
            if(A[j] < A[minj]){
                minj = j;
            }
        }
        swap(A[i], A[minj]);
        if(i != minj) c++;
    }
    return c;
}

int main(){
    int N;
    cin >> N;
    vi A(N);
    rep(i, N){
        cin >> A[i];
    }
    int ans = selectionSort(A, N);
    rep(i, N){
        cout << A[i] << (i == N-1 ? "" : " ");
    }
    cout << endl << ans << endl;
}
