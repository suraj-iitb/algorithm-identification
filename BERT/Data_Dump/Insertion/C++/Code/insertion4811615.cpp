#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < n; i++)
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  int a[101];
  rep(i, n) cin >> a[i];
  
  rep(j, n){
    if(j) cout << " ";
    cout << a[j];
  }
  cout << endl;
  
  int v;
  int j;
  for(int i=1; i<n; i++){
    v = a[i];
    j = i-1;
    
    while(j>=0 && a[j]>v){
      a[j+1] = a[j];
      a[j] = v;
      j--;
    }
    
    rep(j, n){
      if(j) cout << " ";
      cout << a[j];
    }
    cout << endl;
  }
  return 0;
}

