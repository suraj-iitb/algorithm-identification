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

void myprint(vector<int> a){
  REP(i,a.size()){
      cout << a[i];
      if(i != a.size()-1) cout << " ";
  }

    cout << endl;
    
}

int main (){
  int N;
  while (cin >> N){
    vector<int> a;
    REP(i,N){
      int ia;
      cin >> ia;
      a.push_back(ia);
    }
    myprint(a);
    
    FOR(i,1,N){
      int v = a[i];
      int j = i-1;
      for(; j>=0 && v < a[j]; j--){
	a[j+1] = a[j];
      }
      a[j+1] = v;
      myprint(a);
    }
    
    a.clear();
  }
  return 0;
}

