#include <stdio.h>
int main(){

  int i,j,array[100],n,count=0,t;
  
  scanf("%d",&n);
  for(i=0; i<n; i++){
    scanf("%d",&array[i]);
  }
 
  for(i=0; i<n-1;i++){
    for(j=0; j<n-1;j++){
      if(array[j]>array[j+1]){
	t=array[j];
	array[j]=array[j+1];
	array[j+1]=t;
	count++;
      }
    }
  }

  for(i=0; i<n; i++){
    printf("%d",array[i]);
    if(i<n-1)
      printf(" ");
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
 
