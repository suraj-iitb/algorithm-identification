#include<stdio.h>
 
int main(){
  int length,A[100],i=0,j=0,flag=0,key;
 
  scanf("%d",&length);
 
  while(i < length){
    scanf("%d",&A[i]);
    i++;
  }
 
  for(i = 0;i < length-1;i++){
    for(j = length-1;j >= 1;j--){
 
      if(A[j] < A[j-1]){
    key = A[j-1];
    A[j-1] = A[j];
    A[j] = key;
    flag++;
      }
    }
  }
 for(i = 0;i < length-1;i++){
      printf("%d ",A[i]);
    }
    printf("%d\n",A[i]);
    printf("%d\n",flag);
    return 0;
}
