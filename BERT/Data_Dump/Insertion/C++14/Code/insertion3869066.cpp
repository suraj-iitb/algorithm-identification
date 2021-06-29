#include <bits/stdc++.h>
using namespace std;

using i8  = int8_t;using i16 = int16_t;using i32 = int32_t;using i64 = int64_t;using u8  = uint8_t;using u16 = uint16_t;using u32 = uint32_t;using u64 = uint64_t;using f32 = float;using f64 = double;
using vi32 = vector<i32>;using vi64 = vector<i64>;using vvi32 = vector<vi32>;using vvi64 = vector<vi64>;using pi32 = pair<i32,i32>;using pi64 = pair<i64,i64>;

#define FOR(i,a,b) for(i64 i=(a), i##_len=(b); i<i##_len; ++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,x) for(i64 i=1;i<=(i64)(x);i++)
#define RREPS(i,x) for(i64 i=((i64)(x));i>0;i--)
#define ALL(obj) (obj).begin(),(obj).end()
#define SZ(x) ((i64)(x).size())
#define CLR(ar,val) memset(ar, val, sizeof(ar))
#define cauto const auto&
#define pb push_back
#define mp make_pair
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
#define perm(c) sort(ALL(c));for(bool c##p=1;c##p;c##p=next_permutation(all(c)))

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

template<class T> inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }


void Main();
i32 main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(15);
    Main();
    return 0;
}

void Main() {
    //---
    i32 n; cin >> n;
    int arr[n];
    REP(i,n) cin >> arr[i];
    for (i32 i = 0; i < n; i++) cout << arr[i] << (i == (n-1) ? "" : " " );
    cout << endl;
    for (i32 i = 1; i < n; i++) {
        i32 v = arr[i];
        i32 j = i - 1;
        while (j >= 0 && arr[j] > v) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = v;

        for (i32 i = 0; i < n; i++) cout << arr[i] << (i == (n-1) ? "" : " " );
        cout << endl;
    }

    //---
}