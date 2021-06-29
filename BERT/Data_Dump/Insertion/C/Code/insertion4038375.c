#include<stdio.h>
int main(){
  int length,data[100],i,j,k,v;
  
  
  //input
  scanf("%d",&length);
  
  for(i=0;i<length;i++){
    scanf("%d",&data[i]);
  }

  //output
  for(k=0;k<length;k++){
    if(k+1==length){
      printf("%d",data[k]);
    }
    else{
      printf("%d ",data[k]);
    }
  }
  printf("\n");

  
  for(i=1;i<length;i++){
    
    v = data[i];
    j = i-1;
    
    while(j>=0 && data[j]>v){
      data[j+1] = data[j];
      j--;
    }
    data[j+1] = v;
    
    
    //output
    for(k=0;k<length;k++){
      if(k+1==length){
	printf("%d",data[k]);
      }
      else{
	printf("%d ",data[k]);
      }
    }
    printf("\n");
     
  }
  
  return 0;
}

