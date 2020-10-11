#include<stdio.h>

int main(void){
  int a[100],n,i,j,k,temp,count=0,min,flag=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n-1;i++){
    min=a[i];
    k=i;
    for(j=i+1;j<n;j++){
      if(a[j]<min){
	min=a[j];
	k=j;
	flag=1;
      }
    }
    if(flag==1){
      count++;
      flag=0;
    }
    temp=a[i];
    a[i]=a[k];
    a[k]=temp;
  }
  for(i=0;i<n-1;i++){
      printf("%d ",a[i]);
  }
  printf("%d",a[n-1]);
  printf("\n");
  printf("%d\n",count);
}
  

