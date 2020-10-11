#include<stdio.h>
#include<stdlib.h>

#define INFTY 1000000001

int count=0;

void merge(int [],int,int,int);
void mergeSort(int [],int,int);

int main(){
  int *S;
  int n, i;
  
  scanf("%d",&n);
  S = (int *)malloc(n * sizeof(int));
 
  for(i=0; i<n; i++)
    scanf("%d",&S[i]);

  mergeSort(S, 0, n);

  for(i=0; i<n; i++){
    printf("%d",S[i]);
    if(i<n-1)
      printf(" ");
  }
  printf("\n%d\n",count);
  
  free(S);
  return 0;
}

void merge(int A[],int l,int m,int r){
  int *L, *R;
  int n1, n2;
  int i, j, k;
  
  n1 = m-l;
  n2 = r-m;

  L = (int *)malloc((n1+1) * sizeof(int));
  R = (int *)malloc((n2+1) * sizeof(int));

  for(i=0; i<n1; i++)
    L[i] = A[l+i];

  for(i=0; i<n2; i++)
    R[i] = A[m+i];

  L[n1] = INFTY;
  R[n2] = INFTY;

  i = j = 0;
  for(k=l; k<r; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
      count++;
    }
    
    else{
      A[k] = R[j];
      j++;
      count++;
    }
  }
  
  free(L);
  free(R);
  return;
}

void mergeSort(int A[],int l,int r){
  int m;
  
  if(l+1 < r){
    m = (l+r)/2;
    mergeSort(A, l, m);
    mergeSort(A, m, r);
    merge(A, l, m, r);
  }
}

