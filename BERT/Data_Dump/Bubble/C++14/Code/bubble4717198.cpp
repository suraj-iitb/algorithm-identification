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
  rep(i,n) cin >> a.at(i);
  int minia,maxa;
  int num = 0;
  rep(j,n){
    rep(i,n-1){
        if(a.at(i) > a.at(i+1) ){
          maxa = a.at(i);
          minia = a.at(i+1);
          a.at(i+1) = maxa;
          a.at(i) = minia;
          num++;
        }
      }
  }
  rep(i,n){
    cout << a.at(i);
    if(i == n-1) break;
    cout << " ";
  }
  cout << endl;
  cout << num << endl;
}
