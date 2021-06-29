#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;i<(n);i++)
#define REP(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define INF LLONG_MAX - 100
#define MOD 1000000007
#define fcout cout << fixed << setprecision(15)
#define int long long
#define yorn(f) puts((f)?"Yes":"No")
#define YORN(f) puts((f)?"YES":"NO")
#define lower_bound lowb
#define upper_bound upb
typedef long long ll;
typedef pair<int, int> P;
typedef priority_queue<int> pque;
int gcd(int a,int b){return b?gcd(b,a%b):a;};
int lcm(int a,int b){return a*b/gcd(a,b);};
int mod(int a,int b){return (a+b-1)/b;};
template<typename A, size_t N, typename T>
void Fill(A(&array)[N],const T &val){std::fill((T*)array,(T*)(array+N),val);}
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;};
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;};

int n, cnt = 0;
int a[500500];
int b[500500];

void merge_sort(int l, int r) {
    if(r - l == 1) return ;

    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid, r);

    // merge
    int lp = l, rp = mid;
    for(int i = l; i < r; i++) {
        if(rp == r) {
            b[i] = a[lp];
            lp++;
        } else if(lp == mid) {
            b[i] = a[rp];
            rp++;
        }

        else if(a[lp] < a[rp]) {
            b[i] = a[lp];
            lp++;
        } else {
            b[i] = a[rp];
            rp++;
        }

        cnt++;
    }

    for(int i = l; i < r; i++) {
        a[i] = b[i];
    }
}

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    rep(i, n) cin >> a[i];

    merge_sort(0, n);

    rep(i, n) {
        if(i) cout << " ";
        cout << a[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
