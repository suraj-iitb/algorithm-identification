#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<b;++i)
using namespace std;
void insertionSort(int a[],int n){
  rep(i,1,n){
    int b=a[i];
    int j=i-1;
    while(j>=0&&a[j]>b){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=b;
    rep(i,0,n) cout<<a[i]<<(i==n-1?"\n":" ");
  }
}
int main(){
  int a[101],n;
  cin>>n;
  rep(i,0,n) cin>>a[i];
  rep(i,0,n) cout<<a[i]<<(i==n-1?"\n":" ");
  insertionSort(a,n);
  return 0;
}
