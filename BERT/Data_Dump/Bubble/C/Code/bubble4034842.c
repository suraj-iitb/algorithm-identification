#include<stdio.h>
#include<stdlib.h>
int main(){
  int *a,n,i,j,sum=0,b;
  scanf("%d",&n);
  a=malloc(4*n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(a[j]<a[j-1]){
	sum++;
	b=a[j];
	a[j]=a[j-1];
	a[j-1]=b;
      }
    }
  }
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",a[i]);
    else printf("%d ",a[i]);
  }
  printf("%d\n",sum);
  return 0;
}

