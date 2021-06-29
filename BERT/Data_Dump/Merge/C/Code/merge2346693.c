#include <stdio.h>
#define MAX 500001
#define INFTY 1000000000

void merge(int *, int, int, int);
void mergeSort(int *, int, int);
int count = 0;

int main(){
  int i,n, A[MAX];
  
  scanf("%d",&n);
  
  for(i = 0; i < n; i++){
    scanf("%d",&A[i]);
  }

  
  mergeSort(A,0,n);

  
  for(i = 0; i < n-1; i++){
    printf("%d ",A[i]);
  }
  printf("%d\n",A[n-1]);
  printf("%d\n",count);

  return 0;
}

void merge(int *A,int left,int mid,int right){
  //printf("in merge func\n");
  int n1,n2,i,j,k,L[MAX],R[MAX];
  n1 = mid - left;
  n2 = right - mid;
  //count++;

  //printf("left: %d, middle: %d, right: %d\n", left, mid, right);

  //printf("debug for 1\n");
  for( i = 0; i < n1; i++){
    L[i] = A[left + i];
  }
  //printf("debug for 2\n");
  // error occurs in this for loop
  for(i = 0; i < n2; i++){
    R[i] = A[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;
  i = 0;
  j = 0;
  
  //printf("debug for 3\n");
  for(k = left; k < right; k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i = i + 1;
    }
    else{ 
      A[k] = R[j];
      j = j + 1;
    }
  }
  //printf("debug: ");
  for(i = 0;*(A+i) != NULL;i++){
    //printf("%d ",*(A+i));
  }
  //printf("\n");
}

void mergeSort(int *A,int left,int right){
  //static int checknum = 1;
  int i;
  int mid;
  //printf("%d: ", checknum);
  for(i = left;i < right;i++){
    //printf("%d ",*(A+i));
  }
  //checknum++;
  //printf("\n");
  if(left+1 < right){
    //count++;
    mid = (left + right)/2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);

  }
}
