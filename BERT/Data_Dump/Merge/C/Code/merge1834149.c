#include<stdio.h>
#define N 500000
#define INF 1000000001

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int count;

int main(){
  int num,n[N],i;

  scanf("%d",&num);

  for(i=0;i<num;i++)  scanf("%d",&n[i]);

    mergeSort(n,0,num);

  for(i=0; i<num-1; i++) printf("%d ",n[i]);
  printf("%d\n%d\n",n[i],count);

  return 0;
}


void merge(int *A,int left,int mid,int right){
  int L[N],R[N],i,j,k,n1,n2;

  n1 = mid-left;
  n2 = right-mid;
  for(i=0; i<n1; i++) L[i]=A[left+i];
  for(i=0; i<n2; i++) R[i]=A[mid+i];

  L[n1]=INF;
  R[n2]=INF;

  i=0;
  j=0;

  for(k=left; k<right;k++){
    if(L[i]<=R[j]){
      A[k]=L[i];
      i++;
      count++;
    }
    else{
      A[k]=R[j];
      j++;
      count++;
    }
  }
}

void mergeSort(int *A,int left,int right){
  int mid;
  if(left+1 < right){
    mid = (left + right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
