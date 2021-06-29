
#include <stdio.h>
#include <stdlib.h>

#define NMIN 1
#define NMAX 100
#define AMIN 0
#define AMAX 100

void selectionSort(int, int *);

int main() {
  int n;
  int *a;
  int i; // counter

  scanf("%d", &n);
  if(n<NMIN||NMAX<n) { // if N is out of range
    fprintf(stderr,"1<=N<=100\n");
    exit(8);
  }
  a = (int *)malloc(sizeof(int)*n);
  for(i=0; i<n; i++) {
    scanf("%d", &a[i]);
    if(a[i]<AMIN||AMAX<a[i]) { // if A[i] is out of range
      fprintf(stderr,"0<=A[i]<=100\n");
      exit(8);
    }
  }

  selectionSort(n,a);

  free(a);
  
  return 0;
}

void selectionSort(int n, int *a) {
  int i, j; // counter
  int minj; // minimum of A[i]
  int tmp; // use to swap
  int cnt=0; // the number of swap operations
  int flag; // if A[i]!=A[minj]
  
  for(i=0; i<n; i++) {
    minj = i;
    flag = 0;
    for(j=i; j<n; j++)
      if(a[j]<a[minj]) {
	minj = j;
	flag = 1;
      }
    tmp = a[i];
    a[i] = a[minj];
    a[minj] = tmp;
    cnt += flag;
  }

  // output
  for(i=0; i<n; i++) {
    printf("%d", a[i]);
    if(i<n-1)
      printf(" ");
    else
      printf("\n");
  }
  printf("%d\n", cnt);
}

