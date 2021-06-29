#include <bits/stdc++.h> 

#define int long long
#define double long double

#define REP(i, b) for(int i = 0; i < (b); i++)
#define REPS(i, b) for(int i = 1; i <= (b); i++)
#define ALL(v) (v).begin(), (v).end()

#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

using pi = pair<int, int>;
using vi = vector<int>;
using vd = vector<double>;
using vs = vector<string>;
using vb = vector<bool>;
using vpi = vector<pi>;
using vvi = vector<vi>;
using vvb = vector<vb>;

const int INF = 1e16;
const int MOD = 1e9+7;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int c = 0;

void bubbleSort(vi& A, int N)
{
    bool frag = true;
    while(frag)
    {
        frag = false;
        for(int j = N-1; j > 0; j--)
        {
            if(A[j] < A[j-1]) 
            {
                swap(A[j], A[j-1]);
                c++;
                frag = true;
            }
        }
    }
}

signed main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(10);

    int N; cin >> N;
    vi A(N); REP(i, N) cin >> A[i];
    bubbleSort(A, N);
    cout << A[0];
    for(int i = 1; i < N; i++) cout << " " << A[i];
    cout << endl;
    cout << c << endl;
}
