#include <stdio.h>
#define N 10000

int linearSearch(int*,int,int);

int main(){
  int n,q,i,S[N+1],t,count=0;

  scanf("%d",&n);
  for(i = 0;i < n;i++) scanf("%d",&S[i]);
  scanf("%d",&q);
  for(i = 0;i < q;i++){
    scanf("%d",&t);
    if(linearSearch(S,n,t)) count++;
  }
  
  printf("%d\n",count);

  return 0;
}

int linearSearch(int U[],int m,int key){
  int j = 0;
  U[m] = key;
  while(U[j] != key) j++;
  return j != m;
}
