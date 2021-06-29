#include<iostream>
#include<stdio.h>
#include<string>
#include <algorithm>
#include<cstring>
#include <math.h>
#include <iomanip>
using namespace std;


void insertionSort(int* a,int n)
{
  int v;
  for(int j=0;j<n;j++){
    if(j)cout<<" ";
    cout<<a[j];
  }
  cout<<endl;
  for(int i=1;i<n;i++){
    v=a[i];
    int j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    for(int j=0;j<n;j++){
      if(j)cout<<" ";
      cout<<a[j];
    }
    cout<<endl;
  }
}

int main()
{
  int n;
  int a[1000];

  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }

  insertionSort(a,n);

  return 0;
}

