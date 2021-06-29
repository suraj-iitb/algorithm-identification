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

void bubblesort(int a[],int n){
  bool flag=1;
  int res=0;
  while (flag){
    flag=0;
    for(int j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){
        swap(a[j],a[j-1]);
        res++;
        flag=1;
      }
    }
  }
  trace(a,n);
  cout<<res<<endl;
}

int main() {
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++) cin>>a[i];
  bubblesort(a,n);
  return 0;
}

