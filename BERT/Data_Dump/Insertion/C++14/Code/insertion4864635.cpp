#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin >> a.at(i);
  for(int i=1;i<n;i++){
    for(int k=0;k<n;k++){
      cout << a.at(k) << (k==n-1?'\n':' ');
    }
    int j=i-1,v=a.at(i);
    while(j>=0&&a.at(j)>v){
      a.at(j+1)=a.at(j);
      j--;
    }
    a.at(j+1)=v;
  }
  for(int k=0;k<n;k++){
      cout << a.at(k) << (k==n-1?'\n':' ');
    }
  return 0;
} 
