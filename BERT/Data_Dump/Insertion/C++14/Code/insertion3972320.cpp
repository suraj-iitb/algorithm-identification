#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define countof(a) (sizeof(a)/sizeof((a)[0]))
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i < (n); i++)
#define all(a) begin(a),end(a)
template<class T> istream& operator >> (istream& s, vector<T>& v)
{ for (T& x: v) { s >> x; } return s;}
template<class T> void cout_v(const vector<T>& c)
{ for (int i = 0; i < c.size(); i++) cout << c[i] << endl; }
template<class T> void cout_h(const vector<T>& c)
{ for (int i = 0; i < c.size(); i++) cout << c[i] << (i==c.size()-1?"\n":" "); }
template<class T> inline bool chmin(T& a, T b) {return a>b?a=b,true:false;}
template<class T> inline bool chmax(T& a, T b) {return a<b?a=b,true:false;}
void Yes(bool f){cout<<(f?"Yes":"No")<<endl;}
#define SP << " " <<
#define D(a) cout<<#a<<":"<<a<<"\n"
#define D2(a,b) cout<<#a<<":"<<a<<","<<#b<<":"<<b<<endl 
#define D3(a,b,c) cout<<#a<<":"<<a<<","<<#b<<":"<<b<<","<<#c<<":"<<c <<endl
#define D4(a,b,c,d) cout<<#a<<":"<<a<<","<<#b<<":"<<b<<","<<#c<<":"<<c<<","<<#d<<":"<<d<<endl 
#define MOD 1000000007

template<class T> void insertion_sort(vector<T>& v)
{
    cout_h(v);
    for (int i = 1; i < v.size(); i++) {
        T key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = key;
        cout_h(v);
    }
}

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);
    //cout<<std::fixed<<std::setprecision(10);

    ll N; cin >> N;
    vector<int> v(N); rep(i, N) cin >> v;

    insertion_sort(v);    
}

