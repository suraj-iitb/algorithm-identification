#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[200000];

signed main(){

  int n; cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  int cnt = 0;
  int flag = 1;
  for(int i = 0; i < n; i++){
    flag = 0;
    int minj = i;
    for(int j = i; j < n; j++){
      if(a[j] < a[minj]){
        minj = j;
        flag = 1;
      }
    }
    swap(a[i],a[minj]);
    if(flag) cnt++;
  }

  for(int i = 0; i < n; i++){
    if(i) cout << " ";
    cout << a[i];
  }
  cout << endl;
  cout << cnt << endl;

  return 0;
}

