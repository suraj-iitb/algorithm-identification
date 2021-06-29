#include<iostream>
#include<stdio.h>
#include<string>
#include <algorithm>
#include<cstring>
#include <math.h>
#include <iomanip>
using namespace std;

int selectionSort(int *a,int n)
{
  int ans=0;
  for(int i=0;i<n;i++){
    int minj=i;
    for(int j=i;j<n;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    int b=a[i];
    if(i!=minj)
      ans++;
    a[i]=a[minj];
    a[minj]=b;
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
  int ans=selectionSort(a,n);
  for(int i=0;i<n;i++){
    if(i)cout<<" ";
    cout<<a[i];
  }
  cout<<endl;
  cout<<ans<<endl;
  return 0;
}

