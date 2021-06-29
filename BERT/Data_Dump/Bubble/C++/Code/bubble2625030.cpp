#include<stdio.h>

int main(){
  int n,a[100],d;
  int i,j,k;
  int flag=1,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  while(flag){
    flag=0;
    for(j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
	d=a[j];
	a[j]=a[j-1];
	a[j-1]=d;
	count++;
	flag=1;
      }
    }
  }

  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i<n-1)
      printf(" ");
  }
  printf("\n%d\n",count);

  return 0;
}
