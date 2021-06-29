#include "bits/stdc++.h"
using namespace std;

int main(){
  int cnt = 0,n;

  cin >> n;
  
  int *a = new int[n];

  for(int i=0;i<n;++i) cin >> a[i];

  bool flag = false;
  int minj;
  for(int i=0;i<n;++i){
    flag = false;
    minj = i;
    for(int j=i+1;j<n;++j){
      if(a[j] < a[minj]){
	minj = j;
	flag = true;
      }
    }
    swap(a[i],a[minj]);
    if(flag) ++cnt;
  }

  for(int i=0;i<n;++i){
    cout << a[i];
    if(i != n-1) cout << " ";
  }
  cout << endl << cnt << endl;
  
  delete[] a;
  return 0;
}

