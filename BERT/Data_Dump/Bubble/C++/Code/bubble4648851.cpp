#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n; cin >> n;
  int a[200];
  rep(i,n){
    cin >> a[i];
  }
  int count = 0;
  bool flag = true;

  while(flag){
    flag = false;
    for(int j = n-1; j>0; j--){
      if(a[j] < a[j-1]){
        flag = true;
        swap(a[j],a[j-1]);
        count++;
      }
    }
  }

  rep(i,n){
    if(i>0) cout << " ";
    cout << a[i];
  }
  cout << endl << count << endl;
}

