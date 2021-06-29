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

int cnt=0;
void merge(int s[], int left, int mid, int right) {
  int work[500000];
  for(int i=left;i<=mid;i++) work[i] = s[i];
  for (int i = mid + 1; i <= right; i++)
	work[right - (i - (mid + 1))] = s[i];
  
  int i = left;
  int j = right;
  for(int k=left;k<=right;k++) {
    cnt++;
    if(work[i] < work[j]) {
      s[k] = work[i++];
    } else {
      s[k] = work[j--];
    }
  }  
}

void mergeSort(int s[], int left,int right){
  int mid=(left+right)/2;
  if(left < right){
    mergeSort(s,left,mid);
    mergeSort(s,mid+1,right);
    merge(s,left,mid,right);
  }
  return;
}

int s[500000];
int main(){
  int n; cin>> n;
  //vector<int> s(n);
  rep(i,n) cin >> s[i];
  mergeSort(s,0,n-1);
  //merge(s,0,4,9);
  rep(i,n) {
    cout << (i? " ":"") << s[i];
  }
  cout << endl << cnt << endl;
}

