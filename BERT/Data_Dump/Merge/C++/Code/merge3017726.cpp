
#include <iostream>
#include <sstream>
int INF=1000000000;
int cnt=0;
void merge(int x[],int left,int mid,int right){
  int n1,n2;
  n1=mid-left;
  n2=right-mid;
  int L[n1+1];
  int R[n2+1];
  for(int i=0;i<n1;i++){
    L[i]=x[left+i];
  }
  for(int i=0;i<n2;i++){
    R[i]=x[mid+i];
  }
  L[n1]=R[n2]=INF;
  int i=0,j=0;
  for(int k=left;k<right;k++){
    if(L[i]<=R[j]){
      x[k]=L[i];
      i++;
      cnt++;
    }else{
      x[k]=R[j];
      j++;
      cnt++;
    }
  }
}

void mergeSort(int x[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(x,left,mid);
    mergeSort(x,mid,right);
    merge(x,left,mid,right);
  }
}

int main(){
  int n;
  std::cin>>n;
  int x[n];
  for(int i=0;i<n;i++){
    std::cin>>x[i];
  }
  int left=0;
  int right=n;
  mergeSort(x,left,right);
  for(int i=0;i<n-1;i++){
    std::cout<<x[i]<<" ";
  }
  std::cout<<x[n-1]<<"\n";
  std::cout<<cnt<<"\n";
}

