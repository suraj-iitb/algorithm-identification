#include<stdio.h>
int main(){
  int length,data[100];
  int i,j,minj,datai,count=0;

  
  //input
  scanf("%d",&length);
  
  for(i=0;i<length;i++){
    scanf("%d",&data[i]);
  }
  
  
  for(i=0;i<length;i++){
    minj=i;
    
    for(j=i;j<length;j++){
      if(data[j] < data[minj]){
	minj=j;
      }
    }
    
    if(data[i]!=data[minj]){
      datai=data[i];
      data[i]=data[minj];
      data[minj]=datai;
      count++;
    }
  }
  
  
  //output
  for(i=0;i<length;i++){
    if(i+1==length){
      printf("%d",data[i]);
    }
    else{
      printf("%d ",data[i]);
    }
  } 
  printf("\n%d\n",count);

  
  return 0;
}

