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

int main(){
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) cin >> a[i];
  FOR(i,1,n){
    Output(a);
    int v = a[i], j = i-1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      --j;
    }
    a[j+1] = v;
  }
  Output(a);
  return 0;
}
