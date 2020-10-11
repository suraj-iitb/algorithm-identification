#include<stdio.h>
#include<string.h>

#define N 100

int main(){

  int i,j,n,tmp,min,count=0,a[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){

    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++){
      if(a[j]<a[min]){
	min=j;
      }
    }
    if(a[i]!=a[min]){
    tmp=a[i];
    a[i]=a[min];
    a[min]=tmp;
    count++;
    }
  }
  printf("%d",a[0]);

  for(i=1;i<n;i++){

    printf(" %d",a[i]);
  }
  printf("\n%d\n",count);

  return 0;
}
