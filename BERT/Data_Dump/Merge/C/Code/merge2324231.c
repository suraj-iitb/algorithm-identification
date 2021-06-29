#include<stdio.h>
#define MAX 500000
#define INFTY 1000000000
int cou=0;

 void merge(int A[],int left,int mid,int right){
  int n1=mid-left,n2=right-mid;
  int i,j,L[MAX/2+2],R[MAX/2+2],k; 
  for(i=0;i<n1;i++)L[i]=A[left+i];
  for(i=0;i<n2;i++)R[i]=A[mid+i];
  L[n1]=R[n2]=INFTY;

  i=j=0;

  for(k=left;k<right;k++){
    cou++;
    if(L[i]<=R[j]){A[k]=L[i];i++;}
    else {A[k]=R[j];j++;}

  }
}
void mergeSort(int A[],int left,int right){
  int mid;
  if(left+1 < right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}


int main(){
  int i,n,S[MAX];

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&S[i]);

  mergeSort(S,0,n);

  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i!=n-1)printf(" ");
  }
  printf("\n%d\n",cou);
  return 0;
}
