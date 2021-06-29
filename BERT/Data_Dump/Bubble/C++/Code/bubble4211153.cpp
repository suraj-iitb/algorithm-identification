#include<iostream>
#include<algorithm>
#include<vector>
#include<numeric>
#include<string>
using namespace std;

int main(){
  int n; cin >> n;
  int a[101];
  for (int i=0;i<n;i++) cin >> a[i];

  int ans = 0;
  int flag = 1;

  while (flag){
    flag = 0;
    for(int i=0;i<n-1;i++){
      if (a[i] > a[i+1]){
        swap(a[i],a[i+1]);
        flag = 1;
        ans++;
      }
    }
  }
  for (int i=0;i<n;i++){
    cout << a[i];
    if (i != n-1) cout << " ";
  }
  cout << endl << ans << endl;

  return 0;
}


