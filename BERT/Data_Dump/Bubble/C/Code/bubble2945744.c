#include<stdio.h>
int main(){
  int i,j,k,n,flag=1,temp,c=0;
  int a[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  while(flag){
    flag=0;
    for(j=n-1;j>=1;j--){
      if(a[j]<a[j-1]){
	temp=a[j];
	a[j]=a[j-1];
	a[j-1]=temp;
	flag=1;
	c++;
      }
    }
  }
  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[n-1]);
  printf("%d\n",c);
  return 0;
}
      
  

