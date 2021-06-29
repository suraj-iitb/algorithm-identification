#include <iostream>
#include <vector>
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
using namespace std;
using ll = long long;

void Output(const vector<int> &a){
  REP(i,a.size()){
    cout << a[i];
    if(i != a.size()-1) cout << " ";
  }
  cout << endl;
}

int BubbleSort(vector<int> &a, int n){
  bool flag = 1;
  int res = 0;
  while(flag){
    flag = 0;
    for(int i=n-1;i>=1;--i){
      if(a[i-1] > a[i]){
        swap(a[i-1], a[i]);
        flag = 1;
        ++res;
      }
    }
  }
  return res;
}

int main(){
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int res = BubbleSort(a,n);
  Output(a);
  cout << res << endl;
  return 0;
}
