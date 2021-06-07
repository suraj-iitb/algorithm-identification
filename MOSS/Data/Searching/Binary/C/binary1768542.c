#include<stdio.h>

#define NN 100000
#define NQ 50000

int linearSearch(int *,int ,int);

int main(){

  int n, S[NN], q, T[NQ];
  int i=0,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d", &S[i]);

  scanf("%d",&q);
  for(i=0;i<q;i++)scanf("%d", &T[i]); 

  for(i=0;i<q;i++) if(linearSearch(S, T[i], n)) count++;

  printf("%d\n",count);
  return 0;
}

int linearSearch(int *A, int key, int n)
{

  int mid, left = 0, right = n;

  while(left<right){

    mid = (left + right)/2;

    if(A[mid] == key)    return 1;
    else if(key<A[mid])  right = mid;
    else                 left = mid +1;
  }
    return 0;
}
