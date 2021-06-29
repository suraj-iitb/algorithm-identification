#include<stdio.h>
int main(void){
  int num,i,j,a[100],count=0,min,n,x=0;
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<num;i++){
    min=a[i];
    for(j=num-1;j>i-1;j--){
      if(min>=a[j]){
	min=a[j];
	x=j;
      }
    }
    if(a[i]>a[x]){
      n=a[i];
      a[i]=a[x];
      a[x]=n;
      count+=1;
    }
    
  }
  for ( i=0; i<num; i++){
    if(i!=num-1) printf("%d ",a[i]);
    else printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}
