#include<stdio.h>
#include<stdlib.h>

int main(){
  int *data, num, flag=1, cnt=0, i;

  //input data
  scanf("%d",&num);
  data=(int *)malloc(num*sizeof(int));
  for(i=0;i<num;i++) scanf("%d",&data[i]);

  
  //bubble sort
  while(flag==1){//flag==1 sort is not finish
    flag=0;

    for(i=num-1;i>0;i--){
      if(data[i]<data[i-1]){
	//data[i]<->data[i-1]
	flag=data[i];
	data[i]=data[i-1];
	data[i-1]=flag;

	flag=1;
	cnt++;//data change count 
      }
      
    }
    
  }

  //output result
  for(i=0;i<num-1;i++) printf("%d ",data[i]);
  printf("%d\n%d\n",data[i],cnt);

  free(data);
  return 0;
}

