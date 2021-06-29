#include<bits/stdc++.h>
using namespace std;
int main(){
  int x=0,n,a[100];
  cin>>n;
  for(int i = 0 ; i < n; i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    for(int j=n-1;j>i;j--){
      int tmp;
      if(a[j]<a[j-1]){
	tmp=a[j-1];
	a[j-1]=a[j];
	a[j]=tmp;
	x++;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(i!=0) cout<<" ";
    cout<<a[i];
  }
  cout<<endl<<x<<endl;
  return 0;
}


