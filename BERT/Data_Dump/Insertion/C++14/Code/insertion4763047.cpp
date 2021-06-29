#include <bits/stdc++.h>
using namespace std;

# define rep(i, n) for(int(i)=0;(i)<(n);(i)++)
# define reps(i, n) for(int(i)=1;(i)<=(n);(i)++)
# define rrep(i, n) for(int i=((int)(n)); i>0; --i)
# define rreps(i, n) for(int i=((int)(n)); i>=0; --i)
# define ALL(v) v.begin(), v.end()
template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
template<typename T> void dump(T e){std::cout << e << std::endl;}
template<typename T> void dump(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void dump(const std::vector<std::vector<T> >& vv){ for(const auto& v : vv){ dump(v); } }
typedef long long ll;


int main(){
  int n; cin >> n;
  vector <int> a(n);
  rep(i,n) cin >> a[i];
  rep(i,a.size()) {
    rep(k,a.size()) {
      cout << a[k];
      if (k != a.size()-1) cout << " ";
    }
    cout << endl;
    int v = a[i+1];
    int j = i;
    while(j>=0 && a[j]>v) {
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    
  }
}

