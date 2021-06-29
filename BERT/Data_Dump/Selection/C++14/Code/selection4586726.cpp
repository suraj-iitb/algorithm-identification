#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;

int main(){
  
  int n; cin>>n;
  vector<int> a(n);
  int cnt{};
  for(auto &i:a) {
    cin>>i;
  }
  for(int i=0; i<n; i++){
    int minj = i;
    for(int j=i; j<n; j++){
      if(a.at(j)<a.at(minj)){
        minj = j;
      }
    }
    if(i!=minj){
        swap(a.at(i),a.at(minj));
        cnt++;
      }
  }
  for(int i=0; i<n-1; i++) cout << a.at(i)<<' ';
  cout << a.back() << endl;
  cout << cnt << endl;
}
