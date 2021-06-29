
#include<stdio.h>
#define MAX 500000
#define SENTI 2000000000
int count = 0;
int L[MAX / 2 + 2], R[MAX / 2 + 2];

void Marge(int*, int, int, int, int);
void margeSort(int*, int, int, int);

int main(){
  int n, i, A[MAX];

  scanf("%d",&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }

  margeSort(A, n, 0, n);

  for(i = 0 ; i < n ; i++){
    if(i > 0) printf(" ");
    printf("%d",A[i]);
  }

  printf("\n");
  printf("%d\n",count);

  return 0;
}

void Marge(int A[], int n, int l, int m, int r){
  int n1, n2,i,j,k;

  n1 = m - l;
  n2 = r - m;
  for(i = 0 ; i < n1 ; i++){
    L[i] = A[l + i];
  }
  for(i = 0 ; i < n2 ; i++){
    R[i] = A[m + i];
  }
  L[n1] = R[n2] = SENTI;

  i = 0;
  j = 0;
  for(k = l ; k < r ; k++){
    count++;
    if(L[i] <= R[j]){
      A[k] = L[i++];
    }
    else{
      A[k] = R[j++];
    }
  }
}

void margeSort(int A[], int n, int l, int r){
  int m;
  if(l + 1 < r ){
    m = (l + r) / 2;
    margeSort(A, n, l, m);
    margeSort(A, n, m, r);
    Marge(A, n, l, m, r);
  }
}

