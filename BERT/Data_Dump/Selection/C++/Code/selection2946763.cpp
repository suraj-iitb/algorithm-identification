#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int cnt=0;

void selsort(int a[], int n){
  for(int i = 0; i < n; i++){
    int minj = i;
    for(int j = i; j < n; j++)
      if(a[j] < a[minj]) minj = j;
    swap(a[i], a[minj]);
    if(minj!=i)cnt++;
  }
}


int main(){
  
  int n, a[100];
  cin>>n;
  for(int i=0;i<n;i++)cin>>a[i];
  selsort(a,n);
  for(int i=0;i<n-1;i++)printf("%d ",a[i]);cout<<a[n-1]<<endl;
  cout<<cnt<<endl;
  
  return 0;
}

