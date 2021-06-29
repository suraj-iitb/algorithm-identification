
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NMAX 500000
#define SMIN 0
#define SMAX pow(10,9)
#define SENTINEL pow(10,9)+1

void merge(int *, int, int, int);
void mergeSort(int *,int , int);

int cnt=0; // the number of comparisons

int main() {
  int n,q;
  int *S, *m;
  int i; // counter
  
  scanf("%d", &n);
  if(NMAX<n) {
    fprintf(stderr,"n <= %d\n", NMAX);
    exit(8);
  }
  
  S = (int *)malloc(sizeof(int)*n);
  for(i=0; i<n; i++) {
    scanf("%d", &S[i]);
    if(S[i]<SMIN || SMAX<S[i]) {
      fprintf(stderr,"%d <= elements in S <= %.0f\n", SMIN, SMAX);
      exit(8);
    }
  }
  
  mergeSort(S,0,n);
  for(i=0; i<n; i++) {
    printf("%d", S[i]);
    if(i==n-1)
      printf("\n");
    else
      printf(" ");
  }
  printf("%d\n", cnt);
    
  free(S);
    
  return 0;
}

void merge(int *S, int left, int mid, int right) {
  int n1, n2;
  int *L, *R;
  int i, j, k; // counter

  n1 = mid-left;
  n2 = right-mid;
  L = (int *)malloc(sizeof(int)*(n1+1));
  R = (int *)malloc(sizeof(int)*(n2+1));

  for(i=0; i<n1; i++)
    L[i] = S[left+i];
  for(j=0; j<n2; j++)
    R[j] = S[mid+j];
  L[n1] = SENTINEL;
  R[n2] = SENTINEL;

  i = 0;
  j = 0;
  for(k=left; k<right; k++) {
    if(L[i] <=  R[j]) {
      S[k] = L[i];
      i++;
      cnt++;
    }
    else {
      S[k] = R[j];
      j++;
      cnt++;
    }
  }

  free(L);
  free(R);
}

void mergeSort(int *S, int left, int right) {
  int mid;
  int i; // counter

  if(left+1 < right) {
    mid = (left+right)/2;
    mergeSort(S, left, mid);
    mergeSort(S, mid, right);
    merge(S, left, mid, right);
  }
}

