#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,c=0;
  cin>>n;
  vector<int>a(n);
  for(int i=0;i<n;i++)cin>>a[i];
  for(int i=0;i<n;i++){
    int m=i;
    for(int j=i;j<n;j++){
      if(a[j]<a[m])m=j;
    }
    if(i!=m){
      c++;
      swap(a[i],a[m]);
    }
  }
  for(int i=0;i<n;i++)cout<<a[i]<<(i==n-1?'\n':' ');
  cout<<c<<endl;
  return 0;
}
