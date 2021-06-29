#include<bits/stdc++.h>
using namespace std;

void insertionsort(int n){
  vector<int> a(n);
  for(int i = 0; i < n; i++) cin >> a[i];
  for(int i = 0; i < n; i++){
    for(int j = i; j > 0; j--){
      if(a[j-1] > a[j]){
        int t = a[j-1];
        a[j-1] = a[j];
        a[j] = t;
      }else break;
    }
    for(int j = 0; j < n; j++){
      cout << a[j];
      if(j != n-1) cout << " ";
    }
    cout << endl;
  }
}

int main(){
  int n;
  cin >> n;
  insertionsort(n);
  return 0;
}

