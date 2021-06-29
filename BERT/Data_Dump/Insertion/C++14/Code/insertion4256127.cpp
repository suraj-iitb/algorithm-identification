#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int>data(n);
  for(int i = 0;i < n;i++){
    cin >> data[i];
    cout << data[i];
    if(i == n-1) cout << "" << endl;
    else cout << " ";
  }
  for(int i = 0;i < n;i++){
    for(int j = i-1;j >= 0;j--){
      if(data[j] > data[j+1]){
        int a  = data[j],b = data[j+1];
        data[j] = b;
        data[j+1] = a;
      }
      if(j == 0){
        for(int k = 0;k < n;k++){
          cout << data[k];
          if(k == n-1) cout << "" << endl;
          else cout << " ";
        }
      }
    }
  }
  
}

