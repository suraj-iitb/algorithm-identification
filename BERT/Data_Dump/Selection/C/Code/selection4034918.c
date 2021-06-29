#include<stdio.h>
#include<stdlib.h>
int main(){
  int *a,n,i,j,sum=0,b,mini;
  scanf("%d",&n);
  a=malloc(4*n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    mini=i;
    for(j=i;j<n;j++){
      if(a[mini]>a[j]){
	
	mini=j;
      }
    }
    if(i!=mini){
      sum++;
      b=a[mini];
      a[mini]=a[i];
      a[i]=b;
    }
  }
  for(i=0;i<n;i++){
    if(i==n-1)printf("%d\n",a[i]);
    else printf("%d ",a[i]);
  }
  printf("%d\n",sum);
  return 0;
}

