#include <bits/stdc++.h>
#define REP(i,n) for (long long i=0;i<(n);i++)
#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RREP(i,n) for(long long i=n;i>=0;i--)
#define RFOR(i,a,b) for(long long i=(a);i>(b);i--)
#define dump1d_arr(array) REP(i,array.size()) cerr << #array << "[" << (i) << "] ==> " << (array[i]) << endl
#define dump2d_arr(array) REP(i,array.size()) REP(j,array[i].size()) cerr << #array << "[" << (i) << "]" << "[" << (j) << "] ==> " << (array[i][j]) << endl
#define dump(x)  cerr << #x << " => " << (x) << endl
#define dumpP(p) cerr << "( " << p.first << " , " << p.second << " )" << ends
#define SORT(c) sort((c).begin(),(c).end())
#define MIN(vec) *min_element(vec.begin(), vec.end())
#define MAX(vec) *max_element(vec.begin(), vec.end())
#define UNIQ(vec) vec.erase(unique(vec.begin(), vec.end()),vec.end()) //ソートの必要あり
#define IN(n,m)  (!(m.find(n) == m.end()))
#define ENUM(m) for (auto itr = m.begin(); itr != m.end(); ++itr)
#define dump_MAP(m) for(auto itr = m.begin(); itr != m.end(); ++itr) { cerr << itr->first << " --> "  << itr->second << endl; }
#define FINDL(vec,x) (lower_bound(vec.begin(),vec.end(),x) - vec.begin())
#define FINDU(vec,x) (upper_bound(vec.begin(),vec.end(),x) - vec.begin())
#define ROUND(N) setprecision(N)
#define ROUND_PRlong(N,val) cout << fixed;cout << setprecision(N) << val << endl
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define INARR(h,w,x,y) (0 <= y && y < h && 0 <= x && x < w)
#define EQ(a,b) (abs(a - b) < 1e-10)
using namespace std;
constexpr long dx[4] = {0,1,0,-1};
constexpr long dy[4] = {1,0,-1,0};
constexpr long double pi = M_PI;
constexpr double eps = 1e-10;
constexpr long mod = 1000000007;
constexpr short shINF = 32767;
constexpr long loINF = 2147483647;
constexpr long long llINF = 9223372036854775807;
typedef long long LL;
typedef vector<LL> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<LL,LL> pr;
typedef vector<bool> VB;
typedef vector<pr> VP;
typedef priority_queue<pr,vector<pr>,greater<pr>> pq;

/*
struct Monoid {
    using T = _underlying_set_;
    static  T op(const T& a, const T& b) { return _a_op_b_; }
    static constexpr T id() { return _identity_element_; }
    static T update(const T& a,const T& b) {return _a_update_b_;}
};
*/

template <class Monoid>
class SegTree {
   private:
    using T = typename Monoid::T;
    const size_t n;
    vector<T> t;
    void prop_to(size_t i) { t[i] = Monoid::op(t[2*i+1],t[2*i+2]); }
    // 更新
   public:
    SegTree(size_t m,T val) : n(m){
        t.resize(2*n-1,Monoid::id());
        for (long long i = 0;i < n;i++) t[i+(n-1)] = val;
        for (long long i = (n-2); i >= 0; --i) prop_to(i);
    }

    SegTree(vector<T> &a)
        : n(a.size()){ 
        t.resize(2*n-1,Monoid::id());
        for (long long i = 0;i < n;i++) t[i+(n-1)] = a[i];
        for (long long i = (n-2); i >= 0; --i) prop_to(i);
    }

    T operator[](size_t i) {return t[i+(n-1)];} // 列のi番目を返す

    void update(size_t i, const T& v) { // 列のi番目に対し、vを作用。
        t[i += (n-1)] = Monoid::update(t[i],v);
        while (i && ((--i) >>= 1)) prop_to(i);
        if(n >= 2) prop_to(0);
    }

    T find(size_t l, size_t r) { // [l,r)の範囲で見つける。
        T accl = Monoid::id(), accr = Monoid::id();
        for (l += (n-1), r += (n-1); l < r; l >>= 1, (--r) >>= 1) {
            if(!(l & 1)) accl = Monoid::op(accl, t[l]);
            if(!(r & 1)) accr = Monoid::op(t[r-1], accr);
        }
        return Monoid::op(accl, accr);
    }
};

//モノイド
struct RMQ { //区間の最小値
    using T = long;
    static T op(const T& a, const T& b) { return min(a, b); }         //モノイド演算
    static constexpr T id() {return numeric_limits<T>::max(); } //モノイド単位元
    static T update(const T& a,const T& b) {return b != id() ? b : a;}    //更新関数
};

struct RSQ { //区間の合計
    using T = long;
    static T op(const T&a,const T& b) {return a+b;}
    static constexpr T id() {return 0;}
    static T update(const T& a,const T& b) {return a+b;}
};

int main(void) {
    long n,ans = 0;
    cin >> n;
    vector<long> a(102,0);
    SegTree<RSQ> sg(a);
    vector<int> num(n);
    REP(i,n) {
        cin >> num[i];
        ans += (i - sg.find(0,num[i]+1));
        sg.update(num[i],1);
    }
    SORT(num);
    REP(i,n-1) cout << num[i] << " ";
    cout << num[n-1] << endl;
    cout << ans << endl;
}


