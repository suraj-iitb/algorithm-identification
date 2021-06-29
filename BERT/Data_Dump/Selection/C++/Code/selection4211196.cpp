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

  for (int i=0;i<n;i++){
    int minj = i;
    for (int j=i;j<n;j++){
      if (a[j] < a[minj]) minj = j;
    }
    if (minj != i){
      swap(a[i],a[minj]);
      ans++;
    }
  }
  for (int i=0;i<n;i++){
    cout << a[i];
    if (i != n-1) cout << " ";
  }
  cout << endl << ans << endl;

  return 0;
}


