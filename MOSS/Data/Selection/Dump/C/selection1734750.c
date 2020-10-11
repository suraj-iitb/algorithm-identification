#include <stdio.h>

#define N 100
#define A 100

int main(){

  int i,j,in,num[N],count=0,minj,key,min1;

  scanf("%d",&in);

  for(i=0;i<in;i++){
    scanf("%d",&num[i]);
  }

  for(i=0;i<in-1;i++){
    minj=num[i];
    for(j=i;j<in;j++){
      if(num[j]<minj){

	min1=j;
	minj=num[j];
      }
    }
    if(num[i]!=minj){
	key=num[i];
	num[i]=num[min1];
	num[min1]=key;
	count++;
    }
      }
    

      for(i=0;i<in-1;i++){
	printf("%d ",num[i]);
      }
      printf("%d",num[i]);
      printf("\n");
      printf("%d\n",count);

      return 0;
}
 
