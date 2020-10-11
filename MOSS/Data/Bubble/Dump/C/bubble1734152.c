#include <stdio.h>
int main()
{
  int n,i,j,flag,s,count=0;
  int array[100];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&array[i]);
  }
  flag=1;
  while(flag==1){
    flag=0;
    for(j=n-1;j>0;j--){
      if(array[j]<array[j-1]){
	s=array[j];
	array[j]=array[j-1];
	array[j-1]=s;
	flag=1;
	count++;
      }
    }
  }

  for(j=0;j<n-1;j++){
    printf("%d ",array[j]);
  }
  printf("%d\n",array[n-1]);
  printf("%d\n",count);

  return 0;
}
