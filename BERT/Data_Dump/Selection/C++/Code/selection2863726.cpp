#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <sstream>
#include <complex>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#include <fstream>
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()
#define ALL(s) (s).begin(), (s).end()
using namespace std;
typedef long long unsigned int llu;
typedef long long ll;


int main (){
  int N;
  while (cin >> N){
    vector<int> a;
    REP(i,N){
      int ia;
      cin >> ia;
      a.push_back(ia);
    }

    int cnt = 0;
    REP(i,N){
      int minj = i;
      FOR(j,i,N){
	if(a[j] < a[minj]) minj = j;
      }
      if(i!=minj){
	swap(a[i],a[minj]);
	cnt++;
      }
    }

    REP(i,N-1){
      cout << a[i] << " ";
    }
    cout << a[N-1] << endl;
    cout << cnt << endl;
  }
  return 0;
}

