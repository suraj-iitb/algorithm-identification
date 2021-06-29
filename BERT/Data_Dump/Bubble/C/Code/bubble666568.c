#include<stdio.h>
main(){
  int n,data[100],i,j,tmp,count;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&data[i]);
  for(i=0;i<n;i++)
    for(j=n-1;j>i;j--)
    if(data[j]<data[j-1]){
      tmp=data[j];
      data[j]=data[j-1];
      data[j-1]=tmp;
      count++;
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
