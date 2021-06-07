#include <stdio.h>

#define NOT_FOUND 0

int linearSearch(int);
int n,A[10000];
int main()
{
  int i,q,count=0,T[500];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&T[i]);
    if(linearSearch(T[i])==1) count++;
  }
  printf("%d\n",count);
  return 0;
}
int linearSearch(int key)
{
  int i;
  for(i=0;i<n;i++){
    if(A[i]==key){
      return 1;
    } 
  }
  return NOT_FOUND;
}
