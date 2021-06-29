#include<bits/stdc++.h>
using namespace std;
void shinobu(int a[],int n){
  for(int i=0;i<n;++i) cout<<a[i]<<(i==n-1?"\n":" ");
}
void bubbleSort(int a[],int n){
  int i,tmp,flag=1,cnt=0;
  while(flag){
    flag=0;
    for(i=n-1;i>0;--i){
      if(a[i]<a[i-1]){
	tmp=a[i];
	a[i]=a[i-1];
	a[i-1]=tmp;
	flag=1;
	cnt++;
      }
    }
  }
  shinobu(a,n);
  cout<<cnt<<endl;
}
int main(){
  int i,n,a[101];
  cin>>n;
  for(i=0;i<n;++i) cin>>a[i];
  bubbleSort(a,n);
  return 0;
}
