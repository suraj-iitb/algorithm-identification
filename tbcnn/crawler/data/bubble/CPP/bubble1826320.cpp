#include<iostream>
using namespace std;
int main(){
  int n,count=0;
  int a[101]={};
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  
  for(int j=0;j<n;j++)
    for(int i=0;i<n;i++)
      if(a[i-1]>a[i]){
	swap(a[i-1],a[i]);
	count++;
      }
    for(int i=0;i<n-1;i++)
      cout<<a[i]<<' ';
    cout<<a[n-1]<<endl<<count<<endl;
    return 0;
}
