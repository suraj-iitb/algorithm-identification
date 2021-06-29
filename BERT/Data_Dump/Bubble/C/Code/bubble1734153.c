#include<stdio.h>
#define N 100

int main(){

  int i,j,n,tmp,count=0,a[N];

  scanf("%d",&n);

  for(i=0;i<n;i++){

    scanf("%d",&a[i]);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(a[j]<a[j-1]){
	tmp=a[j-1];
	a[j-1]=a[j];
	a[j]=tmp;
	count++;
      }
    }
  }
  printf("%d",a[0]);

  for(i=1;i<n;i++){

    printf(" %d",a[i]);
  }
  printf("\n%d\n",count);

  return 0;
}
