#include<stdio.h>
#include<stdlib.h>
// #include<math.h>

// #define INFTY FP_INFINITE
#define INFTY 2147483647

int ct=0;

void printer(int *array, int fst, int n){
  int i;
  for(i=fst; i<n; i++){
    printf("%d",array[i]);
    if(i != n-1) printf(" ");
    else printf("\n");
  }
}


void merge(int *A, int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  int *L = (int *)malloc(sizeof(int) * (n1 + 1));
  int *R = (int *)malloc(sizeof(int) * (n2 + 1));
  int i, j, k;

  // printf(">>merge(in) : ");
  // printer(A, left, right);
  // printf("   %d %d %d %d %d\n",left, mid, right, n1, n2);

  for(i=0; i<n1; i++){
    L[i] = A[left + i];
  }
  for(i=0; i<n2; i++){
    R[i] = A[mid + i];
  }
  L[n1] = INFTY;
  R[n2] = INFTY;

  // printf("   L : ");
  // printer(L, 0, n1+1);
  // printf("   R : ");
  // printer(R, 0, n2+1);

  i = 0;
  j = 0;
  for(k=left; k<right; k++){
    ct++;
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }
    else{
      A[k] = R[j];
      j++;
    }
  }

  // printf(">>merge(out) : ");
  // printer(A, left, right);
  // printf("\n");

}

void mergeSort(int *A, int left, int right){
  int mid;

  // printer(A, left, right);

  if(left+1 < right){
    mid = (left + right) / 2;
    // puts("left");
    mergeSort(A, left, mid);
    // puts ("right");
    mergeSort(A, mid, right);
    // puts("merge");
    merge(A, left, mid, right);
  }
}


int main(){
  int n, *S;
  int i;

  scanf("%d", &n);
  S = (int *)malloc(sizeof(int) * n);
  for(i=0; i<n; i++){
    scanf("%d",&S[i]);
  }

  mergeSort(S, 0, n);

  printer(S, 0, n);
  printf("%d\n",ct);

  return 0;
}

