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
  for(int i = 0; i < n-1; i++){
    int mn = i;
    bool flg = false;
    for(int j = i+1; j < n; j++){
      if(a[j] < a[mn]){
        mn = j;
        flg = true;
      }
    }
    if(flg) cnt++;
    swap(a[i], a[mn]);
  }
  for(int i = 0; i < n; i++){
    cout << a[i];
    if(i == n-1) cout << endl;
    else cout << " ";
  }
  cout << cnt << endl;
  return 0;
}

