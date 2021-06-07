#include<stdio.h>
#include<stdlib.h>

int linearSearch(int);

int n,*S;

int main()
{
  int q,i,x,c = 0;
  int *T;

  scanf("%d",&n);
  S = (int *)malloc(sizeof(int) * n);
  if(S == NULL) exit(1);
  for(i = 0;i < n;i++){
    scanf("%d",&S[i]);
  }

  scanf("%d",&q);
  T = (int *)malloc(sizeof(int) * q);
  if(T == NULL) exit(1);
  for(i = 0;i < q;i++){
    scanf("%d",&T[i]);
    }
  
  for(i = 0;i < q;i++){
    x = linearSearch(T[i]);
    if(x != -1) c ++;
  }
  printf("%d\n",c);
  return 0;
}

int linearSearch(int key)
{
  int i;
  
  i = 0;
  S[n] = key;

  while(S[i] != key){
    i++;
    if(i == n) return -1;
  }
  return i;
}
 
