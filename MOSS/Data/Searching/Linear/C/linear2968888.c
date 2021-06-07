#include<stdio.h>
#include<stdlib.h>

#define FOUND 1
#define NOT_FOUND -1

int search(int [], int, int);

int main(){
  int *S, *T;
  int n, q;
  int count = 0;
  int i, j;
  
  scanf("%d",&n);
  S = (int *)malloc((n+1) * sizeof(int));

  for(i=0; i<n; i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);
  T = (int *)malloc(q * sizeof(int));
  
  for(i=0; i<q; i++)
    scanf("%d",&T[i]);
 
  for(i=0; i<q; i++){
    if(search(S, n, T[i])==FOUND)
    count++;
  }

  printf("%d\n",count);

  free(S);
  free(T);
  return 0;
}

int search(int A[], int n, int key){
  int i=0;
  A[n] = key;

  while(A[i]!=key)
    i++;

  if(i==n)
    return NOT_FOUND;
  
  return FOUND;
}

