#include <iostream>
using namespace std;

int main(){
  int n,i,j,count=0,temp;
  cin>>n;
  int a[n];
  for (i=0;i<n;i++)cin>>a[i];

  for (i=0;i<n;i++){
    for (j=n-1;j>i;j--){
      if (a[j]<a[j-1]){
        temp=a[j];
        a[j]=a[j-1];
        a[j-1]=temp;
        count++;
      }
    }
  }
  for (i=0;i<n;i++){
    if (i)cout<<' ';
    cout<<a[i];
  }
  cout<<endl;
  cout<<count<<endl;
}

