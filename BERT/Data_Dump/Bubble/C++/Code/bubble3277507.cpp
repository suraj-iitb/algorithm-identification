#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[200000];

signed main(){

  int n; cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int flag = 1;
  int cnt = 0;
  while(flag){
    flag = 0;
    for(int j = n-1; j > 0; j--){
      if(a[j] < a[j-1]){
        swap(a[j],a[j-1]);
        flag = 1;
        cnt++;
      }
    }
  }

  for(int i = 0; i < n; i++){
    if(i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  cout << cnt << endl;

  return 0;
}

