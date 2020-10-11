#include <stdio.h>

int main (){
  int num,i,tmp,flag,cnt=0;
  
  scanf("%d",&num);
  int array[num];

  for (i=0;i<num;i++){
    scanf("%d",&array[i]);
  }

  flag = 1;

  while(flag==1){
    flag = 0;

    for(i=num-1;i>0;i--){
      if(array[i]<array[i-1]){
	tmp=array[i-1];
	array[i-1]=array[i];
	array[i]=tmp;
	cnt++;
	flag=1;
      }
      
    }
  }

  for(i=0;i<num-1;i++) printf("%d ",array[i]);
  printf("%d\n",array[num-1]);
  printf("%d\n",cnt);

  return 0;
  
}

