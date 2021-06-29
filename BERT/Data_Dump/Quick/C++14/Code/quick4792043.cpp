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

struct trump {
  int num,id;
  char ch;
};

int partition(vector<trump>& a, int p, int r){
  int x = a[r].num;
  int i = p-1;
  for(int j=p; j<r; j++){
    if (a[j].num <= x) {
      i++;
      swap(a[i],a[j]);
    }
  }
  swap(a[i+1],a[r]);
  return i+1;
}

void qsort(vector<trump>&a, int p, int r) {
  if(p<r){
    int q = partition(a,p,r);
    qsort(a,p,q-1);
    qsort(a,q+1,r);
  }
}




int main() {
  int n; cin >> n;
  vector <trump> a(n); 
  rep(i,n) {
    cin >> a[i].ch >> a[i].num;
    a[i].id=i;
  }
  qsort(a,0,n-1);

  bool flg=true;
  for(int i=1;i<n;i++){
//    dump(i);
//    dump(a[i].ch);
//    dump(a[i-1].num);
//    dump(a[i].num);
//    dump("===");
    if(a[i-1].num<a[i].num || a[i-1].id<a[i].id)continue;
    flg=false;
    break;
  }
  
  cout << (flg? "Stable":"Not stable") << endl;
  rep(i,n) {
    cout << a[i].ch << " " << a[i].num << endl;
  }

    
    
}
