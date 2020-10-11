#include<stdio.h>
#define SENTINEL 1000000000
#define N 500000
int count=0;

void Merge(int A[],int left,int mid,int right){

  int n1=mid - left,n2=right - mid,i,j,k;
  int L[n1+1],R[n2+1];

  for(i = 0; i < n1; i++){

    L[i] = A[left + i];
  }

  for(i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }

  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  i = 0;
  j = 0;

  for(k = left; k < right; k++){

    count++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i += 1;
    }
    else{
    
      A[k] = R[j];
      j += 1;
    }
  }
}

void Merge_Sort(int A[],int left,int right){

  int mid;
  if(left + 1 < right){

    mid = (left + right) / 2;
    Merge_Sort(A,left,mid);
    Merge_Sort(A,mid,right);
    Merge(A,left,mid,right);

  }
}

int main(){

  int n,A[N],i;

  scanf("%d",&n);

  for(i = 0; i < n; i++){

    scanf("%d",&A[i]);
  }

  Merge_Sort(A,0,n);

  for(i = 0; i < n-1; i++){

    printf("%d ",A[i]);
  }
  printf("%d\n",A[i]);
  printf("%d\n",count);

  return 0;
}
