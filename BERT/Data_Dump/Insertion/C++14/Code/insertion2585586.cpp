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
  vector<int> v;

  cin >> n;
  v.resize(n);
  REP( i, n){
    cin >> v[i];
  }

  int key;
  int j;
  for( int i = 1; i < v.size()+1; ++i){
    REP( k, n-1){
      std::cout << v[k] << " ";
    }
    cout << v[n-1] << '\n';
    key = v[i];
    j = i-1;
    while( j >= 0 && v[j] > key){
      v[j+1] = v[j];
      --j;
    }
    v[j+1] = key;
  }

}
