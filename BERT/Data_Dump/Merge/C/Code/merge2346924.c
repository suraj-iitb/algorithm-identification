#include <stdio.h>
#define MAX 500000
#define INFTY 1000000000

void Merge(int*, int, int, int);
void MergeSort(int*, int, int);

int count=0;
int main(){
  int i,n;
  int S[MAX];

  // printf("%d",INFTY);
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }
  /* 
  for(i=0;i<n-1;i++){
    printf("%d ",S[i]);
  }
  printf("%d\n",S[n-1]);
  */
  MergeSort(S, 0, n);

  for(i=0;i<n-1;i++){
    printf("%d ",S[i]);
  }
  printf("%d\n",S[n-1]);
  printf("%d\n",count);

  return 0;
}

void MergeSort(int *A, int left, int right){
  int mid;

  // printf("left: %d, right: %d\n",left,right);
  
  if(left+1 < right){
    mid = (left + right)/2;
    
    // printf("%d\n\n",mid);
    
    //printf("L-M\n");
    MergeSort(A, left, mid);

    //printf("M-R\n");
    MergeSort(A, mid, right);

    //printf("Merge\n");
    Merge(A, left, mid, right);
  }
}

void Merge(int *A, int left, int mid, int right){
  int i,j,k;
  int n1, n2;
  int L[MAX];
  int R[MAX];
  n1 = mid - left;
  n2 = right - mid;

  for(i=0;i<n1;i++){
    L[i] = A[left+i];
  }
  for(i=0;i<n2;i++){
    R[i] = A[mid+i];
  }

  L[n1] = INFTY;
  R[n2] = INFTY;

  i=0;
  j=0;
  
  for(k = left ; k < right ; k++){
    
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
  }
}
