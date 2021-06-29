#include <iostream>
#include <sstream>
#include <cstdio>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int bubblesort(vector<int> &A,int n){
  bool flag=1;
  int cnt = 0;
  while(flag){
    flag=0;
    for(int j=n-1;j>0;j--){
      if(A[j]<A[j-1]){
	swap(A[j],A[j-1]);
	flag=1;
	cnt++;
      }
    }
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
  cnt=bubblesort(a,n);
  for(i=0;i<n-1;i++)
    cout<<a[i]<<" ";
  cout<<a[i]<<endl<<cnt<<endl;
  return 0;
}

