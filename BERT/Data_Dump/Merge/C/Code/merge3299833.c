#include<stdio.h>
#include<stdlib.h>
void merge(int *,int,int,int);
void mergeSort(int *,int,int);
int n,c=0;

int main(){
  int i;
  int *S;
  scanf("%d",&n);
  S=(int *)malloc(n*sizeof(int));
  for(i=0;i<n;i++) scanf("%d",&S[i]);
  
  
  mergeSort(S,0,n);
  
  for(i=0;i<n;i++){
    printf("%d",S[i]);
    if(i<n-1) printf(" ");
  }
  printf("\n%d\n",c);

  free(S);
  return 0;
}

void merge(int *A,int left,int mid, int right){
  int n1,n2,i,j,k,L[mid-left],R[right-mid];
  n1=mid-left;
  n2=right-mid;
  
  for(i=0;i<n1;i++) L[i]=A[left+i];

  for(i=0;i<n2;i++) R[i]=A[mid+i];

  L[n1]=999999999;
  R[n2]=999999999;
  i=0;
  j=0;

  for(k=left;k<right;k++){

    if(L[i]<R[j]){
      A[k]=L[i];
      i++;

    }else{
      A[k]=R[j];
      j++;
    }
    c++;
  }
  
}

void mergeSort(int *A,int left,int right){
  int mid;
  
  if(left+1<right){
    mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
  
}

