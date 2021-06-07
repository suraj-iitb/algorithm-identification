#include<stdio.h>
#define MAX 10000
#define M 500
#define NOT_FOUND -1

int Search(int *,int,int);

int main()
{
  int i,j,n,q,a,count;
  int A[MAX],B[M];

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(j = 0;j < q;j++){
    scanf("%d",&B[j]);
  }

  for(j = 0;j < q;j++){
    a = Search(A,n,B[j]);
    if(a != NOT_FOUND) count++;
  }
  printf("%d\n",count);
  return 0;
}

int Search(int *A,int n,int key){
  int i = 0;
  A[n] = key;
  while(A[i] != key){
    i++;
    if(i == n) return NOT_FOUND;
  }
  return i;
}
