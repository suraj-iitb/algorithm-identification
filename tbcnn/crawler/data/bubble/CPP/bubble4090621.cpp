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



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int N, a[100];
    cin >> N;
    rep(i, N) cin >> a[i];

    bool flag = 1;
    int cnt = 0;

    for(int i = N - 1; i > 0; i--) {
        for(int j = 0; j < i; j++) {
            if(a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                cnt++;
            }
        }
    }

    rep(i, N) {
        if(i == N - 1) cout << a[i];
        else cout << a[i] << " ";
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}
