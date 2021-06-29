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

int SelectionSort(vector<int> &a, int n){
  int res = 0;
  REP(i,n){
    int minj = i;
    FOR(j,i,n){
      if(a[minj] > a[j]) minj = j;
    }
    if(i != minj){
      swap(a[i], a[minj]);
      ++res;
    }
  }
  return res;
}

int main(){
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  int res = SelectionSort(a,n);
  Output(a);
  cout << res << endl;
  return 0;
}
