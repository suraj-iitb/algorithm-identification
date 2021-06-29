#include<stdio.h>
#include<stdlib.h>

#define NMAX 10000
#define QMAX 500

int linearSearch(int *, int, int);


int main(void){
  int n, Sn[NMAX+1], q, Tq;
  int i, cnt=0;

  scanf("%d", &n);
  if(n > NMAX) exit(1);

  for(i=0;i<n;i++)  scanf("%d", &Sn[i]);

  scanf("%d", &q);
  if(q > QMAX) exit(2);

  for(i=0;i<q;i++){
    scanf("%d", &Tq);
    if(linearSearch(Sn, n, Tq)) cnt++;
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

