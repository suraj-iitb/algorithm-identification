#include <stdio.h>
int main(void){
  int flag=1;
  int i,j;
  int n,a[100];
  int co=0;
  int x;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  while(flag){
    flag=0;
    for(j=n-1;j>0;j--){
      if(a[j]<a[j-1]){
	x=a[j-1];
	a[j-1]=a[j];
	a[j]=x;
	flag=1;
	co++;
      }
    } 
  }
  printf("%d",a[0]);
  for(i=1;i<n;i++) printf(" %d",a[i]);
  printf("\n");
  printf("%d\n",co);
  return(0);
}

