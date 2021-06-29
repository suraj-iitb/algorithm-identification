#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin >> a.at(i);
  int che=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
      if(a.at(j)>a.at(j+1)){
        che++;
        swap(a.at(j),a.at(j+1));
      }
    }
  }
  for(int i=0;i<n;i++) cout << a.at(i) << (i==n-1?'\n':' ');
  cout << che << endl;
  return 0;
}
