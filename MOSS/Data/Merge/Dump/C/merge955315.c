#include<stdio.h>
long count=0;
void Merge(long A[500000],long left,long int mid,long right){
  long n1,n2,i,k,j;
  n1=mid-left;
  n2=right-mid;
  long int L[n1+1],R[n2+1];
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
    L[n1]=1000000000;
    R[n2]=1000000000;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
    }else{
      A[k]=R[j];
      j=j+1;
    }
    count++;

  }
}


void MergeSort(long A[500000],long left,long right){
  long mid; 
  if(left+1<right){
    mid=(left+right)/2;
    MergeSort(A,left,mid);
    MergeSort(A,mid,right);
    Merge(A,left,mid,right);
  }else return;
}



int main(){
  long S[500000];
  long i,j,n;
  scanf("%ld",&n);
  for(i=0;i<n;i++) scanf("%ld",&S[i]);
  MergeSort(S,0,n);
  for(i=0;i<n;i++){
    if(i==n-1)  printf("%ld\n",S[i]);
    else  printf("%ld ",S[i]);
  }
  printf("%ld\n",count);  
  return 0;
}
