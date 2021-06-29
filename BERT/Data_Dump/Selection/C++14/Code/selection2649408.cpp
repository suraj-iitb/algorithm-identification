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

  cin >> n;
  a.resize(n);
  REP( i, n){
    cin >> a[i];
  }

  int minj;
  int count = 0;
  int tmp;


  for( int i = 0; i < n; ++i){
    minj = i;
    for( int j = i; j < n; ++j){
      if( a[j] < a[minj]){
        minj = j;
      }
    }
    if( i != minj){
      ++count;
    }
    swap( a[i], a[minj]);
  }

  REP( i, n-1){
    cout << a[i] << " ";
  }
  cout << a[n-1] << endl;
  cout << count << endl;

}
