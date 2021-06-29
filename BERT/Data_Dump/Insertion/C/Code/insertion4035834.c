#include<stdio.h>


int main(){
  int i,j,k,l,num,N,array[100];

  scanf("%d",&N);
  for(i=0;i<N; i++){
    scanf("%d",&array[i]);
  }

  for(i=1;i<=N;i++){
    
    for(k=0;k<N;k++){
      printf("%d",array[k]);
      if(k!=N-1) printf(" ");
      else  printf("\n");
    }
    
    num=array[i];
    j=i-1;
    while(j>=0 && array[j]>num){
      array[j+1]=array[j];
      j--;
    }
    array[j+1]=num;
   
  }
      

   
  
  return 0;
}    

