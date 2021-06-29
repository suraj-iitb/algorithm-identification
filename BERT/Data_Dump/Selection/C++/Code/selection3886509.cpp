#include <bits/stdc++.h>
using namespace std;
void hj(vector<int> &a,int n,int &d){
  for(int i=0;i<n;i++){
    int minj=i;
    for(int j=i;j<n;j++){
      if(a[j]<a[minj]){
        minj=j;
      }
    }
      swap(a[i],a[minj]);
    if(minj!=i) d++;
  }
}
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int f=0;
  hj(a,n,f);
  for(int i=0;i<n;i++){
    if(i==n-1){
      cout<<a[i]<<endl;
    }
    else{
      cout<<a[i]<<" ";
    }
  }
  cout<<f<<endl;
}
