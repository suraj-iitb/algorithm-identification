#include<iostream>
using namespace std;
int n;
void countingsort(int *a,int k){
  int count[10001]={},b[2000001]={};
  for(int i=0;i<n;++i) ++count[a[i]];
  for(int i=1;i<=k;++i) count[i]+=count[i-1];
  for(int i=n-1;i>=0;--i){
    b[count[a[i]]]=a[i];
    --count[a[i]];
  }    
  for(int i=0;i<n;++i){
    if(i) cout<<" ";
    cout<<b[i+1];
  }
  cout<<endl;
}
int main(){
  int m=0,a[2000000]; cin>>n;
  for(int i=0;i<n;++i){
    cin>>a[i];
    if(m<a[i]) m=a[i];
  }
  countingsort(a,m);
  return 0;
}

