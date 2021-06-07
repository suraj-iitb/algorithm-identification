#include<stdio.h>
#include<stdlib.h>

#define FOUND 1
#define NOT_FOUND -1

int search(int [], int, int);

int main(){
  int *S, *T;
  int n, q;
  int count = 0;
  int i;
  
  scanf("%d",&n);
  S = (int *)malloc(n * sizeof(int));

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
  int left, right, mid;

  left = 0;
  right = n;

  while(left < right){
    mid = (left + right)/2;

    if(key == A[mid])
      return FOUND;

    if(key > A[mid])
      left = mid + 1;
    else if(key < A[mid])
      right = mid;
  }

  return NOT_FOUND;
}

