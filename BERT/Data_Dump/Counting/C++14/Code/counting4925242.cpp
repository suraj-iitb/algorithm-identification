#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int>a(n),b(n),c(10001);
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++)c[a[i]]++;
  for(int i=0;i<10000;i++)c[i+1]+=c[i];
  for(int i=n-1;i>=0;i--){
    b[c[a[i]]-1]=a[i];
    c[a[i]]--;
  }
  for(int i=0;i<n;i++)cout<<b[i]<<(i==n-1?'\n':' ');
}
