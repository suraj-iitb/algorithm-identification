#include <stdio.h>

#define N 100

int main(){
  int a[N],n,i,j,temp,count=0;
  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&a[i]);
  for(i=0; i<n-1; i++){
    for(j=n-1; j>i; j--){
      if(a[j]<a[j-1]){
	temp=a[j];
	a[j]=a[j-1];
	a[j-1]=temp;
	count++;
      }
    }
  }
  for(i=0; i<n-1; i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]);
  printf("%d\n",count);
  return 0;
}

