#include<stdio.h>
#include<stdlib.h>


int main(){
  int mini;
  int *A;
  int j,i;
  int num;
  int N;
  int sum=0;
  int flag;

  scanf("%d",&N);
  A=(int *)malloc(num*sizeof(int));
  for(j=0;j<N;j++)
    scanf("%d",&A[j]);

  for(i=0;i<N;i++){
    mini=i;
    flag=0;
    for(j=i;j<N;j++){
      if(A[j]<A[mini]){
	mini=j;
	flag=1;
      
      }
    }
    if(flag){
      num=A[i];
      A[i]=A[mini];
      A[mini]=num;
      sum++;
    }
     
  }
  
  for(j=0;j<N-1;j++)printf("%d ",A[j]);
  printf("%d\n%d\n",A[j],sum);
  


  
  return 0;
}
  
  

