#include<stdio.h>

int main(){
  
  int i,j,num,num2,count=0;
  int NUM[10001],NUM2[501];
  
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&NUM[i]);
    
  }
  
  scanf("%d",&num2);
  
  for(i=0;i<num2;i++){
    scanf("%d",&NUM2[i]);
    for(j=0;j<num;j++){
      
   
      
      if(NUM[j] == NUM2[i]){
	count++;
	break;
      }
    }
    
  }
  
  printf("%d\n",count);
  
  return 0;
}
