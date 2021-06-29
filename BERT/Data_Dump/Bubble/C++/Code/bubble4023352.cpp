#include<iostream>
#include<stdio.h>
#include<string>
#include <algorithm>
#include<cstring>
#include <math.h>
#include <iomanip>
using namespace std;

int bubbleSort(int *a,int n)
{
  int flag=1;
  int b;
  int ans=0;
  while(flag){
    flag=0;
    for(int j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
	b=a[j];
	a[j]=a[j-1];
	a[j-1]=b;
	flag=1;
	ans++;
      }
    }
  }
  return ans;
}

int main()
{
  int n;
  int a[100];
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  int ans=bubbleSort(a,n);
  for(int i=0;i<n;i++){
    if(i)cout<<" ";
    cout<<a[i];
  }
  cout<<endl;
  cout<<ans<<endl;
  return 0;
}

