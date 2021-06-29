#include<stdio.h>
#define N 10000
#define M 500

int linearSearch(int A[], int n, int key){
  int i = 0;
  A[n] = key;
  while(A[i] != key) i++;
  if(i == n) return 0;
  return 1;
}

int main(){
  int i,n,A[N + 1],q,key,sum = 0;

  scanf("%d",&q);
  for(i = 0; i < q; i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&n);
  for(i = 0; i < n; i++){
    scanf("%d",&key);
    if(linearSearch(A,q,key)) sum++;
  }
  printf("%d\n",sum);

  return 0;
}

