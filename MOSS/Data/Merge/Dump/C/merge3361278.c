#include<stdio.h>
#define MAX 505000
#define INF 2000000000
int L[MAX/2],R[MAX/2],c=0;
void merge(int A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  n1=mid-left;
  n2=right-mid;
  for(i=0;i<n1;i++) L[i]=A[left+i];
  for(i=0;i<n2;i++) R[i]=A[mid+i];
  L[n1]=INF;
  R[n2]=INF;
  i=0;
  j=0;
  for(k=left;k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
    }
    else{
      A[k]=R[j];
      j++;
    }
    c++;
  }
}

void mergeSort(int A[],int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2 ;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
} 
int main(){
  int i,n,S[MAX];
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  mergeSort(S,0,n);
  for(i=0;i<n;i++){
    if(i) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");
  printf("%d\n",c);
  return 0;
}

