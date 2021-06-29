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

    bool flag = true;
    int cnt = 0;
    while(flag){
      flag = false;
      for(int j = N-1; j > 0; j--){
	if(a[j] < a[j-1]){
	  swap(a[j],a[j-1]);
	  cnt++;
	  flag = true;
	}
      }
    }
    
    REP(i,N-1){
      cout << a[i] << " ";
    }
    cout << a[N-1] << endl;
    cout << cnt << endl;
    a.clear();
  }
  return 0;
}

