#include <stdio.h>
#define N 100

int main(){

  int n,i,j,temp,flag=0;
  int array[N];

  scanf("%d",&n);

  for(i=0;i<n;i++)
    scanf("%d",&array[i]);

  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(array[j]<array[j-1]){

	temp=array[j];
	array[j]=array[j-1];
	array[j-1]=temp;
	flag++;

      }

    }
  }

  for(i=0;i<n-1;i++)
    printf("%d ",array[i]);

printf("%d",array[n-1]);
  printf("\n");
  printf("%d\n",flag);
  
  return 0;
}
  
  
