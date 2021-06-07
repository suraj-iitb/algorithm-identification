#include<stdio.h>
int linearSearch(int);
int S[10000],n;

int main()
{

  int i=0,q,T[500],j=0,c=0;

  scanf("%d",&n);

  while(i < n){
    scanf("%d",&S[i]);
    i++;
  }
  
  scanf("%d",&q);
  
  while(j < q){
    scanf("%d",&T[j]);
    j++;
  }
  
  for(i = 0;i < q;i++){
  c += linearSearch(T[i]);
  }
  printf("%d",c);
  printf("\n");
  return 0;
}

int linearSearch(int key)
{
  int i=0;
  S[n] = key;
  while(S[i] != key){
    i++;
    if(i == n) return 0;
  }
  return 1;
}
