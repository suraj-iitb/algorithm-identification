#include<stdio.h>
int main(){
  
  int arr[100];
  int a=0,i,j,temp,count=0,x;
  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&arr[i]);
  }
  
  for(i=0;i<x-1;i++){
  
    for(j=0;j<x-1;j++){

      if (arr[j]>arr[j+1]){

	temp=arr[j];
	arr[j]=arr[j+1];
	arr[j+1]=temp;
	count=count++;
      }
      
      /*	for(a=0;a<x;a++){
		printf("%d",arr[a]);
	  if(a<x-1)printf(" ");
	  }
	printf("\n");
 
      */

    }
  }
  
  for(i=0;i<x;i++){
    printf("%d",arr[i]);
    if(i<x-1)printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
