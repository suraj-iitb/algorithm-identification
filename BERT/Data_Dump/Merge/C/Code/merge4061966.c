#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define INF INT_MAX

int cnt,n;

void merge(int *,int,int,int);
void MergeSort(int *,int,int);

int main(){
  int i;
  int *A;
  cnt=0;
  
  scanf("%d",&n);
  A = (int *)malloc(n*sizeof(int));
  for(i=0; i<n; i++)scanf("%d",&A[i]);
  
  MergeSort(A,0,n);
  
  for(i=0; i<n; i++){
    if(i != 0) printf(" ");
    printf("%d",A[i]);
    }
  printf("\n");
  
  printf("%d\n",cnt);

  free(A);
  
  return 0;
}


void merge(int A[],int left,int mid,int right){
  int n1,n2,i,j,k;
  
  n1 = mid - left;
  n2 = right - mid;
  
  int *l,*r;
  l = (int *)malloc((n1+2)*sizeof(int));
  r = (int *)malloc((n2+2)*sizeof(int));
  
  for(i=0; i<n1; i++) l[i] = A[left+i];
  for(i=0; i<n2; i++) r[i] = A[mid+i];
  l[n1]=r[n2]=INF;
  
  i=j=0;
  for(k=left; k<right; k++){
    cnt++;
    if(l[i] <= r[j]){
      A[k] = l[i];
      i++;
    }else{
      A[k] = r[j];
      j++;
    }
  }
  
  free(l);
  free(r);
}

void MergeSort(int A[],int left,int right){
  int mid;
  
  if(left+1 < right ){
    mid = (left + right) / 2;
    MergeSort(A,left,mid);
    MergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
  
}

