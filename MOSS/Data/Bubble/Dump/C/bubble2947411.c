#include <stdio.h>
int main(){
  int n,i,j,a[100],hako,count=0,flag=1;

  scanf("%d",&n);
  for(i=0;i < n;i++){
    scanf("%d",&a[i]);
  }
  while(flag){
    flag=0;
    for(j=n-1;j > 0;j--){
      if(a[j] < a[j-1]){
	hako=a[j];
	a[j]=a[j-1];
	a[j-1]=hako;
	flag=1;
	count++;
      }
    }
  }
  for(i=0;i < n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]);
  printf("%d\n",count);

  return 0;
}  

