#include <bits/stdc++.h>
const double PI = acos(-1);
#define rep(i, n) for (int i = 0; i < (int)(n); i++ )
using namespace std;
int findSumOfDigits(int n) {
  int sum = 0;
  while (n > 0) { // n が 0 になるまで
    sum += n % 10;
    n /= 10;
  }
  return sum;
}
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  rep(i,n){
    cout << a[i];
    if(i != n-1) cout << " ";
  }
  cout << endl;
  for(int i = 1; i < n; i++){
    int v = a[i];
    int j = i-1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
    }
    a[j+1] = v;
    rep(k,n){
      cout << a[k];
      if(k != n-1) cout << " ";
    } 
    cout << endl;
  }
}
