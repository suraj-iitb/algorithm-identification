#include<bits/stdc++.h>
using namespace std;

int a[200010];

signed main(){

  int n; cin >> n;
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  for(int i = 0; i < n; i++){
    int v = a[i];
    for(int j = i-1; j >= 0; j--){
      if(a[j] <= v){
        a[j+1] = v;
        break;
      }
      a[j+1] = a[j];
      if(j == 0) a[j] = v;
    }

    for(int j = 0; j < n; j++){
      if(j == n-1) cout << a[j] << endl;
      else cout << a[j] << " ";
    }
  }

  return 0;
}

