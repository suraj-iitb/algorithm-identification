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
  int i, j, k, count, flag, temp;
  REP (i, n) {
    cin >> a [i];
  }
  flag = 1;
  count = 0;
  while (flag) {
    flag = 0;
    for (j = n - 1; j > 0; j--) {
      if (a [j] < a [j - 1]) {
        temp = a [j - 1];
        a [j - 1] = a [j];
        a [j] = temp;
        flag = 1;
        count++;
      }
    }
  }
  cout << a [0];
  REP1 (k, n) {
    cout << " " << a [k];
  }
  cout << endl << count << endl;

  return 0;
}
  
