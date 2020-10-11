#include<stdio.h>
#include<stdlib.h>
int *marge(int[], int, int);
int cnt;
int main(){
  int n, i;
  scanf("%d", &n);
  int *A;
  A = (int *)malloc(sizeof(int) * n);
  for(i = 0; i < n; i++)
    scanf("%d", &A[i]);
  cnt = 0;
  A = marge(A, 0, n);
  for(i = 0; i < n - 1; i++)
    printf("%d ", A[i]);
  printf("%d\n%d\n", A[i], cnt);
  free(A);
  return 0;
}

int *marge(int A[], int l, int r){
  if(l == r - 1){
    int *tmp;
    tmp = (int *)malloc(sizeof(int));
    tmp[0] = A[l];
    return tmp;
  }
  int *L, *R;
  L = (int *)malloc(sizeof(int) * ((r - l) / 2));
  R = (int *)malloc(sizeof(int) * ((r - l + 1) / 2));
  L = marge(A, l, (l + r) / 2);
  R = marge(A, (l + r) / 2, r);
  int *B;
  int i, j, k;
  i = j = k = 0;
  B = (int *)malloc(sizeof(int) * (r - l));
  while(1){
    if(i < (r - l) / 2 & j < (r - l + 1) / 2){
      if(L[i] < R[j]){
	B[k] = L[i];
	i++;
	k++;
      }
      else{
	B[k] = R[j];
	j++;
	k++;
      }
      cnt++;
    }
    else{
      if(i < (r - l) / 2 | j < (r - l + 1) / 2){
	if(i < (r - l) / 2){
	  B[k] = L[i];
	  i++;
	  k++;
	}
	else{
	  B[k] = R[j];
	  j++;
	  k++;
	}
	cnt++;
      }
      else
	break;
    }
  }
  free(L);
  free(R);
  return B;
}
