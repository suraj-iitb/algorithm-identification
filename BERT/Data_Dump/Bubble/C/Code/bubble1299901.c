#include<stdio.h>
int main(void){
  int num,n,i,j,a[100],flag,count=0;
  scanf("%d",&num);
  for(i=0;i<num;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<num;i++){
	for(j=num-1;j>i-1;j--){
	  if(a[j]<a[j-1]){
	  n=a[j];
	  a[j]=a[j-1];
	  a[j-1]=n;
	  count+=1;
	  }
	  
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
