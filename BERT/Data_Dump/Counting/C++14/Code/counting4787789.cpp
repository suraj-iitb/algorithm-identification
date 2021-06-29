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

template <typename K, typename V, typename C>
void dump_map( const map <K,V,C> & m ) {
    typename map <K,V,C>::const_iterator it = m.begin();
    while( it != m.end() ) {
        cout << it->first << " = " << it->second << endl;
        ++it;
    }
}

template <typename T>
void dump_stack(std::stack<T>& stack) {
  std::stack<T> temp;
  while (!stack.empty()) {
    T top = stack.top(); stack.pop();
    std::cout << top << " ";
    temp.push(top);
  }
  std::cout << endl;
  while (!temp.empty()) {
    T top = temp.top(); temp.pop();
    stack.push(top);
  }
}
template <typename T>
void dump_queue(std::queue<T>& queue) {
  std::queue<T> temp;
  while (!queue.empty()) {
    T top = queue.front(); queue.pop();
    std::cout << top << " ";
    temp.push(top);
  }
  std::cout << endl;
  while (!temp.empty()) {
    T top = temp.front(); temp.pop();
    queue.push(top);
  }
}

typedef long long ll;

int main() {
  int n; cin >> n;
  vector <int> a(n),b(n); 
  rep(i,n) cin >> a[i];
  int c[2000000];
  rep(i,n) c[i]=0;
  rep(i,n) c[a[i]]++;
//  for(int i=0;i<2000000;i++) c[i]=c[i]+c[i-1];
  rep(i,2000000) c[i]=c[i]+c[i-1];
//  dump(c);
//  exit(0);
  for(int i=n-1;i>=0;i--){
    b[c[a[i]]-1]=a[i];
    c[a[i]]--;
  }
  rep(i,n) {
    cout << (i==0? "":" ") << b[i];
  }
  cout << endl;
}
