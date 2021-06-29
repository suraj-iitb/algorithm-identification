#include<stdio.h>

#define N 10000
#define Q 500

int LinearSearch(int,int);

int S[N];

int main()
{
  int T[Q],n,q,i,count = 0;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);

  for(i = 0; i < q; i++){
    scanf("%d",&T[i]);
    count += LinearSearch(T[i],n);
  }

  printf("%d\n",count);

  return 0;
}

int LinearSearch(int key,int n){

  int i = 0;

  while(S[i] != key){
    i++;
    if(i == n) return 0;
  } 
  return 1;
}
