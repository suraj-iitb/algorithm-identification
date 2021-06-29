#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int merge(vector<int>& a,int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  vector<int> L(n1+1),R(n2+1);
  for(int i=0;i<n1;i++){
    L[i]=a[left+i];
  }
  for(int i=0;i<n2;i++){
    R[i]=a[mid+i];
  }
  L[n1]=INF;
  R[n2]=INF;
  int i,j;
  i=j=0;
  for(int k=left;k<right;k++){
    if(L[i]<=R[j]){
      a[k]=L[i];
      i++;
    }else{
      a[k]=R[j];
      j++;
    }
  }
  int counter=right-left;
  return counter;
}

void mergeSort(int& counter,vector<int>& a,int left,int right){

  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(counter,a,left,mid);
    mergeSort(counter,a,mid,right);
    counter+=merge(a,left,mid,right);
  }
}

int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int ans=0;
  mergeSort(ans,a,0,n);
  for(int i=0;i<n;i++){
    if(i){
      cout<<' ';
    }
    cout<<a[i];
  }
  cout<<endl;
  cout<<ans<<endl;
  return 0;
}
