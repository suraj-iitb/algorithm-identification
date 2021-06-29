#include<bits/stdc++.h>
#define ll long long int
#define FOR(i,a,b) for(ll i=(ll)(a);i<(ll)(b);i++)
#define REP(i,n) FOR(i,0,n)
#define REP1(i,n) FOR(i,1,n)
using namespace std;
 
int main () {
  int n;
  cin >> n;
  int a [n];
  int i, j, k, temp, count, minj;
  REP (k, n) {
    cin >> a [k];
  }
  count = 0;
  REP (i, n) {
    minj = i;
    for (j = i; j < n; j++) {
      if (a [j] < a [minj]) {
        minj = j;
      }
    }
    if (i != minj) {
      temp = a [i];
      a [i] = a [minj];
      a [minj] = temp;
      count++;
    }
  }

  cout << a [0];
  REP1 (k, n) {
    cout << " " << a [k];
  }
  cout << endl << count << endl;
 
  return 0;
}
