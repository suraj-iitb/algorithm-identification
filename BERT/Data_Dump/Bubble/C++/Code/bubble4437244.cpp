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
  int n;
  int flg,cnt,tmp;
  cin >> n;
  a.resize(n);
  for(ii=0;ii<n;ii++){
    cin >> a[ii];
  }

  flg = 1;
  cnt = 0;
  while(flg){
    flg = 0;

    for(jj=n-1;jj>=1;jj--){
      if(a[jj] < a[jj-1]){

        tmp = a[jj];
        a[jj] = a[jj-1];
        a[jj-1] = tmp;
        
        flg = 1;
        cnt++;
      }
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

