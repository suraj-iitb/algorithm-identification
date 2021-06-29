#include<stdio.h>
main(){
  int n,i,j,min,data[100],count=0,tmp;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&data[i]);
  for(i=0;i<n;i++){
    min=i;
    for(j=i+1;j<n;j++)
      if(data[j]<data[min])
        min=j;
    if(data[i]>data[min]){
      tmp=data[i];
      data[i]=data[min];
      data[min]=tmp;
      count++;
    }
  }
  for(i=0;i<n;i++){
    if(i)
      printf(" ");
    printf("%d",data[i]);
  }
  printf("\n");
  printf("%d\n",count);
  return 0;
}
