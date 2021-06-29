#include<iostream>
using namespace std;
#define MAX 500000
#define SENTINEL 2000000000

int G[MAX/2+2],H[MAX/2+2];
int cnt;

void merge(int *,int,int,int,int);
void mergeSort(int *,int,int,int);
int main(){
  int Z[MAX],n,i;
  cnt=0;

  cin>>n;
  for(i=0;i<n;i++){
    cin>>Z[i];
  }
    mergeSort(Z,n,0,n);

    for(i=0;i<n;i++){
        if(i){
            cout<<" ";
        }
        cout<<Z[i];
  }
  cout<<endl;

  cout<<cnt<<endl;

  return 0;
}

void merge(int Z[],int n,int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  for(int i=0;i<n1;i++){
    G[i]=Z[left+i];
  }
  for(int i=0;i<n2;i++){
    H[i]=Z[mid+i];
  }
  G[n1]=H[n2]=SENTINEL;
  int i=0,j=0;
  for(int k=left;k<right;k++){
    cnt++;
    if(G[i]<=H[j]){
      Z[k]=G[i++];
    }
    else{
      Z[k]=H[j++];
    }
  }
}

void mergeSort(int Z[],int n,int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(Z,n,left,mid);
    mergeSort(Z,n,mid,right);
    merge(Z,n,left,mid,right);
  }
}
