#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,num=0;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  for(int j=n-1;j>=1;j--){
    for(int i=n-1;i>=1;i--){
      if(a[i]<a[i-1]){
	int tmp=a[i];
	a[i]=a[i-1];
	a[i-1]=tmp;
	num++;
      }
    }
  }
  for(int i=0;i<n;i++){
    cout<<a[i];
    if(i!=n-1)
      cout<<" ";
  }
  cout<<endl;
  cout<<num<<endl;
  return 0;
}
