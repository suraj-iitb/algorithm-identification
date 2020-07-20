#include <bits/stdc++.h>
using namespace std;
void bbs(vector<int> &a,int n,int &e){
  
  int f=1;
  for(int i=0;f;i++){
    f=0;
    for(int j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
        swap(a[j],a[j-1]);
        e++;
        f=1;
      }
    }
  }
  return ;
}
int main(){
  int n;
  cin>>n;
  int f=0;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  bbs(a,n,f);
  for(int i=0;i<n;i++){
    if(i==n-1){
      cout<<a[i];
    }
    else{
      
    cout<<a[i]<<" ";
    }
  }
  cout<<endl;
  cout<<f<<endl;
}
