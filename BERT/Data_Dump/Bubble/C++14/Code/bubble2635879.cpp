#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

#define REP( i, n) for( int i = 0; i < (n); ++i)
#define FOR( i, a, b) for( int i = (a); i < (b); ++i)

#define pb push_back

const int INF = 100100100;
const int MOD = (int)1e9 + 7;

using ll = long long;

using namespace std;

int main(){

  int n;
  vector<int> a;
  int tmp;
  int count = 0;

  cin >> n;
  a.resize(n);
  REP( i, n){
    cin >> a[i];
  }

  bool f = true;

  while(f){
    f = false;
    for( int j = n-1; j >= 1; --j){
      if( a[j] < a[j-1] ){
        tmp = a[j];
        a[j] = a[j-1];
        a[j-1] = tmp;
        f = true;
        ++count;
      }
    }
  }

  REP( i, n-1){
    cout << a[i] << " ";
  }
  cout << a[n-1] << endl;
  cout << count << endl;
}
