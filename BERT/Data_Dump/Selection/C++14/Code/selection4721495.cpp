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
  int b,c;
  int num;
  int ans = 0;
  rep(i,n){
    int mini = a.at(i);
    for(int j = i; j < n; j++){
      if(mini > a.at(j)){
        mini = a.at(j);
        num = j;
      }
    }
    if(mini < a.at(i)){
        swap(a.at(i),a.at(num));
        ans++;
    }
  }
  rep(i,n){
    cout << a.at(i);
    if(i == n-1) break;
    cout << " ";
  }
  cout << endl << ans << endl;
}
