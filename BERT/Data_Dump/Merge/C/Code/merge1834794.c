#include<stdio.h>
#include<string.h>
#define INFTY 1000000000
#define MAX 5000001

void mergeSort(int,int);
void merge(int,int,int);

int A[MAX],L[MAX],R[MAX],C=0;

int main(){
  
 int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
}

  mergeSort(0,n);
    for(i=0;i<n;i++){
      if(i>0)
	printf(" ");
    printf("%d",A[i]);
}
    printf("\n");
    printf("%d\n",C);
  return 0;
}

void merge(int left,int mid,int right){
  int k,i,j,n1,n2;
  n1 = mid - left;
  n2 = right - mid;
  for (i = 0 ;i<=n1-1;i++){
    L[i] = A[left + i];
  }
  for (i = 0;i<=n2-1;i++){
    R[i] = A[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  for (k = left;k<=right-1;k++){
    if (L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
      C++;
    }
    else {
      A[k] = R[j];
      j = j + 1;
      C++;
    }}
  return ;
}

void mergeSort(int left,int right){
  int mid;
  if(left+1<right){
    mid=(left+right)/2;   
    mergeSort(left,mid);
    mergeSort(mid,right);
    merge(left,mid,right);
  }
  return ;
}
