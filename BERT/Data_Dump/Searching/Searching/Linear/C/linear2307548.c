#include<stdio.h>

#define nmax 10000
#define qmax 500

int linearSearch(int);

int n;
int A[nmax];

int main(){
  int q, i, cnt=0;
  int B[qmax];

  scanf("%d",&n);
  for(i=0; i<n ; i++) scanf("%d",&A[i]);

  scanf("%d",&q);
  for(i=0; i<q ; i++) scanf("%d",&B[i]);

  for(i=0 ; i<q ; i++) cnt += linearSearch(B[i]);

  printf("%d\n",cnt);
  return 0;
}

int linearSearch(int key){
  int i;

  i = 0;
  A[n] = key;
  
  while(A[i] != key) i++;

  if(i==n) return 0;

  return 1;
}
