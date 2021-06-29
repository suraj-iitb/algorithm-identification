#include <bits/stdc++.h>
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); i++) 
#define FOR(i, a, b) for(int (i) = a; (i) < (int)b; i++)
#define RREP(i, n) for(int (i)=((int)(n)-1); (i)>=0; i--)
#define RFOR(i, a, b) for(int (i) =((int)(b)-1); (i)>=(int)a; i--)
#define ALL(v) (v).begin(),(v).end()
#define MOD 1000000007
#define NIL -1
#define FI first
#define SE second
#define MP make_pair
#define PB push_back
#define SZ(x)  (int)x.size()
#define SP(x)  setprecision((int)x)


using namespace std ;
typedef long long ll;
typedef vector<int> vint;
typedef vector<vint> vvint;
typedef vector<string> vstr;
typedef pair<int, int> pii;
const int INF = 1e9;
const ll LINF = 1e18;
const double EPS = 1e-9;
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;} //最大公約数
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;} //最小公倍数

//-------------------------------------------------
//コピペするとこ
void cnt(vector<int> vec){
    int n = SZ(vec) ;
    int cnt=0 ;
    bool flag = true ;
    while(flag){
        flag = false ;
        for(int j=n-1;j>0;j--){
            if(vec.at(j)<vec.at(j-1)){
                int swap = vec.at(j-1) ;
                vec.at(j-1) = vec.at(j) ;
                vec.at(j) = swap ;
                cnt++ ;
              flag = true ;
            }
        }
    }
    cout << cnt <<endl ;
}

void print(vector<int> vec){
    int n = SZ(vec) ;
    sort(ALL(vec)) ;
    REP(i,n){
        cout << vec.at(i) ;
        if(i!=n-1){
            cout <<" ";
        }
    }
    cout <<endl ;
}


//-------------------------------------------------


int main()
{
    int n ;
	cin >> n ;
    vector<int> vec(n) ;
    REP(i,n){
        cin >> vec.at(i) ;
    }
    print(vec) ;
    cnt(vec) ;
    return 0 ;
}


