#include<stdio.h>
int main(){
  int length,data[100];
  int i,flag,datai,count=0;

  //input
  scanf("%d",&length);
  
  for(i=0;i<length;i++){
    scanf("%d",&data[i]);
  }
  
  
  flag=1;
  while(flag){
    flag=0;
    
    for(i=length-1;i>0;i--){
      if(data[i] < data[i-1]){
	datai=data[i];
	data[i]=data[i-1];
	data[i-1]=datai;
	flag=1;
	count++;
      }
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

