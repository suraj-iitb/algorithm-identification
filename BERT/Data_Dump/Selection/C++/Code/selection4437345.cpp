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


int gcd(int x,int y){
  int mi,ma;
  ma = max(x,y);
  mi = min(x,y);
  if(ma % mi == 0){
    return mi;
  }
  else{
    return gcd(mi,ma % mi);
  }
}

int main(){
  long ii,jj,kk;
  vector<int> a;
  int n,minj,cnt,tmp;
  cnt = 0;
  
  cin >> n;

  a.resize(n);

  for(ii=0;ii<n;ii++){
    cin >> a[ii];
  }

  for(ii=0;ii<n;ii++){
    minj = ii;

    for(jj=ii;jj<n;jj++){
      if(a[jj] < a[minj]){
        minj = jj;
      }
    }
    
    if(minj != ii){
      tmp = a[ii];
      a[ii] = a[minj];
      a[minj] = tmp;

      cnt++;
    }
    
  }

  vector<int>::iterator it;
  it = a.begin();

  while(it != a.end()){
    cout << *it ;
    it++;
    if(it != a.end()){
      cout << " ";
    }
  }
  cout << endl;

  cout << cnt <<endl;
  return 0;
}

