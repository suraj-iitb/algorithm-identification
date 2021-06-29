#include<bits/stdc++.h>
using namespace std;
int a[500000],cnt,l[250005],r[250005];
void merge(int left,int mid,int right){
  int x=mid-left,y=right-mid;
  for(int i=0;i<x;++i) l[i]=a[left+i];
  for(int i=0;i<y;++i) r[i]=a[mid+i];
  l[x]=r[y]=1000000001;
  x=y=0;
  for(int i=left;i<right;++i){
    ++cnt;
    if(l[x]<=r[y]) a[i]=l[x++];
    else a[i]=r[y++];
  }
}

void mergesort(int left,int right){
  if(left+1<right){
    int mid=(right+left)/2;
    mergesort(left,mid);
    mergesort(mid,right);
    merge(left,mid,right);
  }
}

int main(){
  int n; cin>>n;
  for(int i=0;i<n;++i) cin>>a[i];
  mergesort(0,n);
  for(int i=0;i<n;++i){
    if(i) cout<<" ";
    cout<<a[i];
  }
  cout<<endl;
  cout<<cnt<<endl;
  return 0;
}

