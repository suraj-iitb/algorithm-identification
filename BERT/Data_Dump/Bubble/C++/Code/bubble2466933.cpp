#include<iostream>
#include<algorithm>
using namespace std;
int main(){
  int n,a[100],cnt=0,flag=1;
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  while(flag){
    flag=0;
    for(int j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
	swap(a[j],a[j-1]);
	flag=1;
	cnt++;
      }
    }
  }
  for(int i=0;i<n;i++){
    cout<<a[i];
    if(i==n-1)cout<<endl;
    else cout<<" ";
  }
  cout<<cnt<<endl;
  return 0;
}
