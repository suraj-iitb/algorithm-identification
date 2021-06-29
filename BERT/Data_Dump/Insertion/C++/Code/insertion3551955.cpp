#include <iostream>
using namespace std;

int main(){
  int n,i,j,v,k;
  cin>>n;
  int a[n];
  for (i=0;i<n;i++)cin>>a[i];
  for (k=0;k<n;k++){
    if (k)cout<<' ';
    cout<<a[k];
  }
  cout<<endl;
  for (i=1;i<n;i++){
    v=a[i];
    for (j=i-1;j>=0&&a[j]>v;j--)a[j+1]=a[j];
    a[j+1]=v;
    for (k=0;k<n;k++){
      if (k)cout<<' ';
      cout<<a[k];
    }
    cout<<endl;
  }
}

