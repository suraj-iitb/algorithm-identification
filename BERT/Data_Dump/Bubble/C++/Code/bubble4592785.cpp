#include<iostream>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<complex>
#include<map>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  int cnt = 0;
  bool flg = true;
  while(flg){
    flg = false;
    for(int i = n-1; i > 0; i--){
      if(a[i-1] > a[i]){
        cnt++;
        swap(a[i-1], a[i]);
        flg = true;
      }
    }
  }
  for(int i = 0; i < n; i++){
    cout << a[i];
    if(i == n-1) cout << endl;
    else cout << " ";
  }
  cout << cnt << endl;
  return 0;
}

