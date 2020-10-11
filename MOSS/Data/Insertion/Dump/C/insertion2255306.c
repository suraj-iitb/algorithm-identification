#include <stdio.h>
#define N 100
int main(){
  int A[N],i,j,num,key;

  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&A[i]);
  }

  for(j=0;j<num;j++){
   printf("%d",A[j]);
   if(j!=num-1)printf(" ");
 }
 printf("\n");


 for(i=1;i<num;i++){
   key=A[i];
    j=i-1;
    while(j>=0 && A[j]>key){
      A[j+1]=A[j];
      j--;
      A[j+1]=key;
    }


    
    for(j=0;j<num;j++){
      printf("%d",A[j]);
      if(j!=num-1)printf(" ");
    }
    printf("\n");


 }
    
 return 0;

}
  
