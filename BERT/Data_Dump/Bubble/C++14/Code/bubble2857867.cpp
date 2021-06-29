#include "bits/stdc++.h"
using namespace std;

int main(){
  int cnt = 0,n;

  cin >> n;
  
  int *a = new int[n];

  for(int i=0;i<n;++i) cin >> a[i];

  
  bool flag = true;
  while(flag){
    flag = false;
    for(int i=n-1;i>0;--i){
      if(a[i] < a[i-1]){
	swap(a[i], a[i-1]);
	flag = true;
	++cnt;
      }
    }
  }

  for(int i=0;i<n;++i){
    cout << a[i];
    if(i != n-1) cout << " ";
  }
  cout << endl << cnt << endl;
  
  delete[] a;
  return 0;
}

