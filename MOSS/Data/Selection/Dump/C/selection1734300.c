#include <stdio.h>
int main()
{
  int i,j,min,n,count=0,s;
  int array[100];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&array[i]);
  }
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(array[j]<array[min]){
	min=j;
      }
    }
    s=array[i];
    array[i]=array[min];
    array[min]=s;
    if(array[i]!=array[min]){
    count++;
    }
  }

  for(i=0;i<n-1;i++){
    printf("%d ",array[i]);
  }
  printf("%d\n",array[i]);
  printf("%d\n",count);
  return 0;
}
