#include<stdio.h>
#include<stdlib.h>

int main(){
  int *data, num, cnt=0, i, j, min;

  //input data
  scanf("%d",&num);
  data=(int *)malloc(num*sizeof(int));
  for(i=0;i<num;i++) scanf("%d",&data[i]);

  
  //selection sort
  for(i=0;i<num;i++){
    min=i;

    for(j=i;j<num;j++) //search minimum data
      if(data[j]<data[min]) min=j;
	

    if(min!=i){
      //data[i]<->data[min]
      j=data[i];
      data[i]=data[min];
      data[min]=j;
      
      cnt++;//minimum value change count
    }
    
  }

  //output result
  for(i=0;i<num-1;i++) printf("%d ",data[i]);
  printf("%d\n%d\n",data[i],cnt);

  free(data);
  return 0;
}

