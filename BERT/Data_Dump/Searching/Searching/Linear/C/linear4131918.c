#include <stdio.h>

int linear(int *,int,int);

int main(){
  int sum=0,len1,len2,i,A[10000],elem;

  scanf("%d",&len1);
  for(i=0;i<len1;i++){
    scanf("%d",&A[i]);
  }
  
  scanf("%d",&len2);
  for(i=0;i<len2;i++){
    scanf("%d",&elem);
    sum+=linear(A,elem,len1);
  }

  printf("%d\n",sum);
  
  return 0;
}

int linear(int A[],int elem,int len){
  int i;
  for(i=0;i<len;i++){
    if(A[i]==elem) return 1;
  }
  return 0;
}

