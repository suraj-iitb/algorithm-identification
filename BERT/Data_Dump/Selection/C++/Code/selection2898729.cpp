#include <bits/stdc++.h>
using namespace std;
int ans = 0;
vector<int> selectionSort(vector<int> v){
  int mi,n = 1;
  bool flag;
  for(int i = 0;i < v.size();i++){
    mi = i;
    flag = false;
    for(int j = i + 1;j < v.size();j++){
      if(v[mi] > v[j]){
        mi = j;
        flag = true;
      }
    }
    if(flag){
      swap(v[i],v[mi]);
      ans++;
    }
  }
  return v;
}

int main() {
  int N;
  cin >> N;
  vector<int> v(N);
  for(int i = 0;i < N;i++)cin >> v[i];
  v = selectionSort(v);
  for(int i = 0;i < v.size();i++){
    if(i != v.size() - 1)cout << v[i] << " ";
    else cout << v[i] << endl;
  }
  cout << ans << endl;
}
