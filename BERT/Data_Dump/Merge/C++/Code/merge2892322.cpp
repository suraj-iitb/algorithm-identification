#include<iostream>
using namespace std;
#define INFTY 100000000000
int c;

int merge(int A[],int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int L[n1],R[n2];

  for(int i=0;i<=n1;i++){
    L[i]=A[left+i];
  }
  for(int i=0;i<=n2;i++){
    R[i]=A[mid+i];
}

  L[n1]=R[n2]=INFTY;

  int i=0,j=0;
  for(int k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
      c++;
    }else{
      A[k]=R[j];
      j++;
      c++;
    }
  }

}

int mergesort(int A[],int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergesort(A,left,mid);
    mergesort(A,mid,right);
    merge(A,left,mid,right);
  }
}

int main(){
  int n;
  cin>>n;
  int S[n];

  for(int i=0;i<n;i++){
    cin>>S[i];
  }

  mergesort(S,0,n);
for(int i=0;i<n-1;i++){
  cout<<S[i]<<" ";
  }
 cout<<S[n-1]<<endl;
 cout<<c<<endl;

 return 0;
}

