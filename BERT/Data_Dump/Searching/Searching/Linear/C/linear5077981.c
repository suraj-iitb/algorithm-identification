#include<stdio.h>
#define M 1000

int main(){
  
  int A[10000],T[500],a,b,count=0,i,j,k[100];
  
  scanf("%d",&a);
  
  for(i=0; i < a; i++){
    
    scanf("%d",&A[i]);
    
  }
  
  scanf("%d",&b);
  
  for(i=0; i < b; i++){
    
    scanf("%d",&T[i]);
    
  }
  for(i=0; i < M; i++){
    count=count+k[i];
  }
  count=0;
  for(i=0; i < b; i++){
    
    for(j=0; j < a; j++){
      
      if(T[i]==A[j]){
	
	count++;
	
	break;
	
      }
    }
  }
  
  printf("%d\n",count);

  return 0;
}

