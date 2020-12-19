#include <bits/stdc++.h>
using namespace std;

int a[2000002] = {};
int b[2000002] = {};
int cnt[10002] = {};

int main(){

  int n;

  cin >> n;
  for(int i = 1; i <= n; i++){
    cin >> a[i];
    cnt[a[i]]++;
  }
  for(int i = 1; i <= 10000; i++) cnt[i] += cnt[i-1];
  for(int i = 1; i <= n; i++) b[cnt[a[i]]--] = a[i];
  for(int i = 1; i <= n; i++){
    cout << b[i] << (i != n ? " " : "\n");
  }
  return 0;
}
