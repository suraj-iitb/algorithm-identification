#include <stdio.h>

#define Max 100

int main(){

  int i,num,j,temp,array[Max],min,count=0,flag=0;

  
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&array[i]);
  }

  for(i=0;i<num;i++){
    min=i;
    for(j=i;j<num;j++){
      if(array[j]<array[min]){
	min = j;
	flag = 1;
      }
      
    }
    if(flag == 1){count++;
      flag = 0;}
    
    temp = array[i];
    array[i]=array[min];
    array[min] = temp;
    
  }
  for(i=0;i<num-1;i++){
    printf("%d ",array[i]);

  }
  printf("%d\n",array[num-1]);
  printf("%d\n",count);
}
	
