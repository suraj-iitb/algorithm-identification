#include <stdio.h>

#define NOT_FOUND -1
#define MAX 10000
#define MAX2 500

int LinearSearch(int [],int,int);

int main(){
  int n,q,S[MAX + 1],T[MAX2];
  int sum = 0;
  int i;

  scanf("%d",&n);
    
  for (i = 0;i < n;i++)
    scanf("%d",&S[i]);

  scanf("%d",&q);

  for (i = 0;i < q;i++)
    scanf("%d",&T[i]);

  for (i = 0;i < q;i++)
    if (LinearSearch(S,n,T[i]) != -1)
      sum++;

  printf("%d\n",sum);
  
  return 0;
}

int LinearSearch(int S[],int n,int key){
  int i;

  S[n] = key;
  i = 0;
  
  while (S[i] != key)
    i++;

  if (i == n)
    return NOT_FOUND;

  return i;
}

