#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
typedef long long ll;

void trace(int a[],int n){
  int i;
  for(i=0;i<n;i++){
    if(i>0) cout<<' ';
    cout<<a[i];
  }
  cout<<endl;
}

int selectionsort(int a[],int n){
  int res=0;
  for(int i=0;i<n;i++){
    int minj=i;
    for(int j=i;j<n;j++){
      if(a[j]<a[minj]) minj=j;
    }
    swap(a[i],a[minj]);
    if(i!=minj) res++;
  }
  return res;
}

int main() {
  int n,res;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  res=selectionsort(a,n);
  trace(a,n);
  cout<<res<<endl;
  return 0;
}

