#include<stdio.h>
void merge(int *,int,int,int);
void mergeSort(int *,int,int);
int S[500000],count=0;
int main(){
  int i,j,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&S[i]);
  mergeSort(S,0,n);
  for(i=0;i<n;i++){
    if(i>0) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n%d\n",count);
  return 0;
}
 
void merge(int A[],int left,int mid,int right){
  int n1=mid-left,n2=right-mid,i,L[n1+1],R[n2+1],j,k;
  for(i=0;i<=n1-1;i++){
    L[i]=A[left+i];
  }
  for(i=0;i<=n2-1;i++){
    R[i]=A[mid+i];
  }
  L[n1]=1000000000;
  R[n2]=1000000000;
  i=0;
  j=0;
  for(k=left;k<=right-1;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i=i+1;
    }
     
    else{
      S[k]=R[j];
      j=j+1;
    }
    count++;
  }
}
void mergeSort(int S[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(S,left,mid); 
    mergeSort(S,mid,right);
    merge(S,left,mid,right);
  }
}
     
