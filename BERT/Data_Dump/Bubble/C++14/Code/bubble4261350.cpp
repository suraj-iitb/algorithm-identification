#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,cnt = 0;
  cin >> n;
  vector<int>data(n);
  for(int i = 0;i < n;i++){
    cin >> data[i];
  }
  for(int i = 0;i < n;i++){
    for(int j = n-1;j > i;j--){
      if(data[j] < data[j-1]){
        int a = data[j],b = data[j-1];
        data[j] = b;
        data[j-1] = a;
        cnt++;
      }
    }
  }
  for(int i = 0;i < n;i++){
    cout << data[i];
    if(i == n-1) cout << "" << endl;
    else cout << " ";
  }
  cout << cnt << endl;
}

