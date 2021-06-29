#include <algorithm>
#include<iostream>
#include<vector>
#include<deque>
#include<queue>
#include<list>
#include<stack>
#include<map>
#include<set>
#include<string>
#include <sstream>
#include<bitset>

#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>

using namespace std;


int main(){
  long ii,jj,kk;
  vector<int> a;

  int n;
  cin >> n;
  a.resize(n);

  for(ii=0;ii<n;ii++){
    cin >> a[ii];
  }
  int v;
  for(ii=0;ii<n;ii++){
    v = a[ii];
    jj = ii-1;
      
    while( jj >= 0 && a[jj] > v){
      a[jj+1] = a[jj];
      jj--;
    }
    a[jj+1] = v;

    for(jj=0;jj<n;jj++){
      cout << a[jj];
      if(jj != n-1){
        cout << " " ;
      }
    }
    cout << endl;
  }
  
  
  return 0;
}

