#include<stdio.h>
 
int main(){
 
  int num,i,j,k,v;
  int A[1000];
 
 
  scanf("%d",&num);
 
  for(i=0;i<num;i++){
    scanf("%d",&A[i]);
  }
 
    for(i=0;i<num-1;i++){
      printf("%d ",A[i]);
    }
    printf("%d\n",A[i]);
 
  for(i = 1 ; i <= num-1 ; i++){
    v=A[i];
    j=i-1;
 
    while(j>=0 && A[j]>v){
 
      A[j+1]=A[j];
      j--;
    }
      A[j+1]=v;
     
 
    for(k=0;k<num-1;k++){
      printf("%d ",A[k]);
    }
    printf("%d\n",A[k]);
     
  }
  return 0;
}
