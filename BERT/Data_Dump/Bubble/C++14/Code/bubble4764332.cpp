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
  vector <int> A(n);
  rep(i,n) {
    cin >> A[i];
  }
  bool flg=true;
  int c=0;
  while(flg) {
    flg=false;
    rep(i,A.size()) {
      if (A[i] < A[i-1]) {
        int tmp = A[i];
        A[i] = A[i-1];
        A[i-1] = tmp;
        flg = true;
        c++;
      }
    }
  }
  rep(i,A.size()) {
      cout << A[i] ;
      if (i != A.size()-1) {cout << " ";}
  }
  cout << endl;
  cout << c << endl;
}

