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

#define INF 0x7fffffff

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

int cnt;

void merge(vector<int>* a,int left ,int mid,int right){
  int n1,n2;
  int ii,jj,kk;
  vector<int> l,r;

  n1 = mid -left;
  n2 = right - mid;
  
  l.resize(n1+1);
  r.resize(n2+1);

  for(ii=0;ii<=n1-1;ii++){
    l[ii] = a->at(left+ii);
  }

  for(ii=0;ii<=n2-1;ii++){
    r[ii] = a->at(mid+ii);
  }

  l[n1] = INF;
  r[n2] = INF;

  ii = 0;
  jj = 0;

  for(kk = left; kk<= right -1; kk++){
    if(l[ii] <= r[jj]){
      a->at(kk) = l[ii];
      ii++;
      cnt++;
    }
    else{
      a->at(kk) = r[jj];
      jj++;
      cnt++;
    }
  }
  
}

void mergeSort(vector<int>* a,int left,int right){

  if(left+1 < right){
    int mid = (left+right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid,right);
    merge(a,left,mid,right);
  }
}


int main(){
  long ii,jj,kk;
  vector<int> a;
  int n;

  cin >> n;

  a.resize(n);

  for(ii=0;ii<n;ii++){
    cin >> a[ii];
  }

  cnt = 0;
  mergeSort(&a,0,n);

  for(ii=0;ii<n;ii++){
    cout << a[ii];
    if(ii!= n-1){
      cout << " ";
    }
  }
  
  cout << endl;

  cout << cnt << endl;
  
  return 0;
}

