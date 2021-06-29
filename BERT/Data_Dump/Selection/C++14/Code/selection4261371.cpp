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
    int max = 101,maxpos;
    for(int j = n-1;j >= i;j--){
      if(data[j] <= max){
        max = data[j];
        maxpos = j;
      }
    }
    if(maxpos != i){
      cnt++;
      int a = data[i],b = data[maxpos];
      data[i] = b;
      data[maxpos] = a;
    }
  }
  for(int i = 0;i < n;i++){
    cout << data[i];
    if(i == n-1) cout << "" << endl;
    else cout << " ";
  }
  cout << cnt << endl;
}

