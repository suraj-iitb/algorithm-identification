#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define M 500000

void merge(int *,int,int,int);
void mergeSort(int *,int,int);

int count=0;
int S[M];

int main(){
  int n,i;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  mergeSort(S,0,n);

  for(i=0;i<n;i++){
    if(i<n-1) printf("%d ",S[i]);
    else printf("%d\n",S[i]);
  }
  printf("%d\n",count);

  return 0;
}

void merge(int *A,int left,int mid,int right){
  int n1,n2,i,j,k;
  int *L,*R;

  n1 = mid - left;
  n2 = right - mid;

  L = malloc((n1+1)*sizeof(int));
  R = malloc((n2+1)*sizeof(int));

 for(i=0;i<n1;i++){
   L[i]=A[left+i];
 }
 for(i=0;i<n2;i++){
   R[i]=A[mid+i];
 }
 
   L[n1]=INT_MAX;
   R[n2]=INT_MAX;
   i=0;
   j=0;
 
   for(k=left;k<right;k++){
     if(L[i]<=R[j]){
       A[k]=L[i];
       i++;
     }
     else{
       A[k] = R[j];
       j++;
     }
     count++;
   }
 
}

void mergeSort(int *A,int left,int right){
  int mid;

  if(left+1<right) {
    mid = (left+right)/2;

    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
