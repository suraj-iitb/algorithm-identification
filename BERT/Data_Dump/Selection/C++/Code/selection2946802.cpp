#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int selectionsort(vector<int> &A,int n){
  int minj,i,j,cnt = 0;
  for(i=0;i<n-1;i++){
    minj=i;
    for(j=i;j<n;j++){
      if(A[j]<A[minj]){
	minj=j;
      }
    }
    if(A[i]!=A[minj])cnt++;
    swap(A[i],A[minj]);
  }
  return cnt;
}

int main(){
  vector<int>a;
  int n,cnt,i;
  cin>>n;
  for (i=0;i<n;i++){
    cin>>cnt;
    a.push_back(cnt);
  }
  cnt=selectionsort(a,n);
  for(i=0;i<n-1;i++)
    cout<<a[i]<<" ";
  cout<<a[i]<<endl<<cnt<<endl;
  return 0;
}

