#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &a, int n){
  bool flag = true;
  int cnt = 0;
  
  while(flag){
    flag = false;
    for(int i = n-1; i > 0; i--){
      if(a[i] < a[i - 1]){
        int tmp = a[i];
        a[i] = a[i - 1];
        a[i - 1] = tmp;
        flag = true;
        cnt++;
      }
    }
  }
  
  for(int i = 0; i < n; i++){
    if(i == n - 1) cout << a[i] << endl;
    else cout << a[i] << " ";
  }
  cout << cnt << endl;
}

int main(){
  int n; cin >> n;
  vector<int> a(n);
  
  for(int i = 0; i < n; i++) cin >> a[i];
  
  bubble_sort(a, n);
}
