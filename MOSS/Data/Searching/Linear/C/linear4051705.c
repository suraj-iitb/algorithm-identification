#include <stdio.h>
#include <stdlib.h>

int A[10000],n;

int linearSearch(int key){
  int i=0;
  while( A[i]!=key){
    i++;
    if(i==n)return 0;
  }
  return 1;
}

int main(){
  int i,j,m,num=0,key;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&A[i]);
  scanf("%d",&m);
  for(j=0;j<m;j++){
    scanf("%d",&key);
    num+=linearSearch(key);
  }
  printf("%d\n",num);

  return 0;
}
   

