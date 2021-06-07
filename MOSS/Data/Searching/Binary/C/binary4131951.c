#include <stdio.h>

int binary(int *,int,int);

int main(){
  int len1,len2,A[100000],elem,sum=0;
  int i;

  scanf("%d",&len1);
  for(i=0;i<len1;i++){
    scanf("%d",&A[i]);
  }

  scanf("%d",&len2);
  for(i=0;i<len2;i++){
    scanf("%d",&elem);
    sum+=binary(A,elem,len1);
  }

  printf("%d\n",sum);
  
  return 0;
}

int binary(int *A,int elem,int len){
  int left=0,right=len,mid;
  
  while(left<right){
    mid=(left+right)/2;
    if(A[mid]==elem) return 1;
    if(A[mid]<elem) left=mid+1;
    else right=mid;
  }

  return 0;
}

