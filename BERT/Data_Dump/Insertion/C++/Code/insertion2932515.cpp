#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int n,i,j,v,k;
  int A[100]={};
  cin>>n;
  for(i=0;i<n;i++){
    cin>>A[i];
  }
  for(k=0;k<n-1;k++){
    cout<<A[k]<<" ";
  }
  cout<<A[k]<<endl;
  for(i=1;i<n;i++){
    v=A[i];
    j=i-1;
    while(j>=0 && A[j]>v){
      A[j+1]=A[j];
      j--;
      A[j+1]=v;
    }
    for(k=0;k<n-1;k++){
      cout<<A[k]<<" ";
    }
    cout<<A[k]<<endl;
  }
  return 0;
}

