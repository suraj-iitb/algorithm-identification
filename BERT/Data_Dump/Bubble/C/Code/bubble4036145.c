#include <stdio.h>
#include <stdlib.h>
#define N 100

int main(){

  int A[N],flag=1,kazu,i,j,kari,kou;

  scanf("%d",&kazu);
  if(kazu>100)exit(1);
  for(i=0;i<kazu;i++){
    scanf("%d",&A[i]);
  }

  while (flag){
    flag = 0;
       for(j=1; j<kazu;j++){
	
	 if (A[j] < A[j-1]){
	   kari=A[j-1];
	   A[j-1]=A[j];
	   A[j]=kari;
	   flag = 1;
	   kou++;
	 }
	 
       }
  }
  for(i=0;i<kazu;i++){
    printf("%d",A[i]);
    if(i<kazu-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",kou);
  
  return 0;
}
  

