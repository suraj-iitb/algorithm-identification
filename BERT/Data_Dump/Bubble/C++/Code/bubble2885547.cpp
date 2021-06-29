
#include<bits/stdc++.h>
using namespace std;
int main(){

  int n,cnt=0;
  cin>>n;

  int a[101];

  for(int i=0;i<n;i++){
    cin>>a[i];
  }


  for(int i=0;i<n;i++){
    for(int j=0;j<n-i-1;j++){
      if(a[j]>a[j+1]){
	cnt++;
	int temp=a[j];
	a[j]=a[j+1];
	a[j+1]=temp;
      }
    }
  }

  for(int i=0;i<n;i++){
    if(i==n-1){
      cout<<a[i]<<endl;
    }else{
      cout<<a[i]<<" ";
    }
  }

  cout<<cnt<<endl;
  return 0;

}

