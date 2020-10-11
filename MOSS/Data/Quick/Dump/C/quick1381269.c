#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int count = 0;
char N[100000];
#define SENTINEL 1000000001
int Partition(int *A, char *C, int f, int l){
  int i, j, x;
  char c;
  i = f-1;
  for(j = f; j < l; j++){
    if(A[j] <= A[l]){
      i = i+1;
      x = A[j];
      A[j] = A[i];
      A[i] = x;

      c = C[j];
      C[j] = C[i];
      C[i] = c;
    }
  }
    x = A[i+1];
    A[i+1] = A[l];
    A[l] = x;

    c = C[i+1];
    C[i+1] = C[l];
    C[l] = c;

  return i+1;
}

void Quicksort(int *A, char *C, int f, int l){
  int q;
  if(f < l){
    q = Partition(A,C,f,l);
    Quicksort(A,C,f,q-1);
    Quicksort(A,C,q+1,l);
  }
}
void Merge(int *B, char *D,int left,int mid,int right){
  int n1, n2, i, j, k, *L, *R;
  char *RC, *LC;
  n1 = mid - left;
  n2 = right - mid;
  L = malloc(sizeof(int)*(n1+1));
  R = malloc(sizeof(int)*(n2+1));
  LC = malloc(sizeof(char)*(n1+1));
  RC = malloc(sizeof(char)*(n2+1));
  for(i = 0; i < n1; i++){
    L[i] = B[left + i];
    LC[i] = D[left + i];
  }
  for(i = 0; i < n2; i++){
    R[i] = B[mid + i];
    RC[i] = D[mid + i];
  }
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;
  LC[n1] = '\0';
  RC[n2] = '\0';
  i = 0;
  j = 0;
  for(k = left; k < right; k++){
    if(L[i] <= R[j]){
      B[k] = L[i];
      D[k] = LC[i];
      i = i + 1;
      count++;
    }
    else{
      B[k] = R[j];
      D[k] = RC[j];
      j = j + 1;
      count++;
    }
  }
}

void Merge_Sort(int *B,char *D,int left,int right){
  int mid, i;
  if(left+1 < right){
    mid = (left + right)/2;
    Merge_Sort(B,D,left, mid);
    Merge_Sort(B,D,mid, right);
    Merge(B,D,left, mid, right);
  }
}
int main(){
  int i, n, *A, *B;
  char *C, *D;
  scanf("%d",&n);
  A = malloc(sizeof(int)*n);
  B = malloc(sizeof(int)*n);
  C = malloc(sizeof(char)*n);
  D = malloc(sizeof(char)*n);
  for(i = 0; i < n; i++){
    scanf(" %c%d",&C[i], &A[i]);
    B[i] = A[i];
    D[i] = C[i];
  }

  Quicksort(A,C,0,n-1);
  Merge_Sort(B,D,0,n);

  if(strcmp(C,D)== 0) printf("Stable\n");
  else printf("Not stable\n");
  for(i = 0; i < n; i++){
    printf("%c %d\n",C[i],A[i]);
  }
  
  return 0;
}
