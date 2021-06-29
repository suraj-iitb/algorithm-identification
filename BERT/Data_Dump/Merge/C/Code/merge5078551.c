#include <stdio.h>
#define INFTY 2000000000

int n,S[500000],c;

void merge(int A[], int l, int m, int r)
{
  int n1 = m - l;
  int n2 = r - m;
  
  int i,j,L[n1],R[n2];
  
  for(i = 0; i < n1; i++) L[i] = A[l+i];
  for(i = 0; i < n2; i++) R[i] = A[m+i];
  L[n1] = INFTY;
  R[n2] = INFTY;

  i = 0; j = 0;

  for(int k = l; k < r; k++){
    c++;
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

void sort(int A[], int l, int r)
{
  if(l+1 < r){
    int m = (l + r) / 2;
    sort(A, l, m);
    sort(A, m, r);
    merge(A, l, m, r);
  }
}

int main()
{
  scanf("%d",&n);
  for(int i = 0; i < n; i++) scanf("%d",&S[i]);

  sort(S, 0, n);

  for(int i = 0; i < n; i++){
    if(i > 0) printf(" ");
    printf("%d",S[i]);
  }
  printf("\n");

  printf("%d\n",c);
}

