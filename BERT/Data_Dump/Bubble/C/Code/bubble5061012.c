
#include <stdio.h>
#include <stdlib.h>

#define NMIN 1
#define NMAX 100
#define AMIN 0
#define AMAX 100

void bubbleSort(int, int *);

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
      fprintf(stderr,"0<=A[i]<=100");
      exit(8);
    }
  }

  bubbleSort(n,a);

  free(a);
  
  return 0;
}

void bubbleSort(int n, int *a) {
  int flag; // possible/impossible to swap
  int cnt=0; // number of swap operations
  int tmp; // use to swap
  int i; // counter
  
  flag = 1;
  while(flag) {
    flag = 0;
    for(i=n-1; i>=1; i--)
      if(a[i]<a[i-1]) {
	tmp = a[i];
	a[i] = a[i-1];
	a[i-1] = tmp;
	flag = 1;
	cnt++;
      }
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

