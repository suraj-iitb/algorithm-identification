#include<stdio.h>
#define N 100000

int linerSearch(int);

int A[N],n;

int main(){

  int m,j,key,count=0;

  scanf("%d",&n);
  for(j = 0 ; j < n ; j++){
    scanf("%d",&A[j]);
  }

  scanf("%d",&m);
  for(j = 0 ; j < m ; j++){
    scanf("%d",&key);
    
    if(linerSearch(key) == 1) count++;
  }

  printf("%d\n",count);
  return 0;
}

int linerSearch(int key)
{
  int i;

  for(i = 0 ; i < n ; i++){
    if(A[i] == key) return 1;
  }
  return 0;
}
