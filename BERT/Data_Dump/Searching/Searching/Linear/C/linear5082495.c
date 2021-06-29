#include<stdio.h>
#include<stdlib.h>

#define NMAX 10000
#define QMAX 500

int linearSearch(int *, int, int);


int main(void){


  int n,i, S[NMAX+1], x, y;
  int cnt=0;

  scanf("%d", &n);


  if(n > NMAX) exit(1);


  for(i=0;i<n;i++)  scanf("%d", &S[i]);

  scanf("%d", &x);

  if(x > QMAX) exit(2);

  for(i=0;i<x;i++){

    scanf("%d", &y);
    if(linearSearch(S, n, y)) cnt++;

  }

  printf("%d\n", cnt);

  return 0;
}

int linearSearch(int A[], int n, int key){

  int i = 0;
  A[n] = key;

  while(A[i] != key) i++;
  return i != n;
}

