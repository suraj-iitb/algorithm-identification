#include <stdio.h>

int a(int n,int A[],int key)
{
  int i;
  
  i = 0;
  A[n] = key;
  while (A[i] != key){
    i++;
  }
  if (i == n){
    return 0;
  }
  return 1;
}


int main()
{
  int n, q, i, count;
  
  scanf("%d",&n);
  int S[n];
  for(i=0;i<n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  int T[q];
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
  }

  count = 0;

  for(i=0;i<q;i++){
    if(a(n,S,T[i]) == 1){
      count++;
    }
  }

  printf("%d\n",count);

  return 0;
}


