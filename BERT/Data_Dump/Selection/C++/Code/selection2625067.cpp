#include<stdio.h>
#define prinf printf

void swap(int *x,int *y){
  int a;
  a=*x;
  *x=*y;
  *y=a;
}

int main(){
  int n,a[100],d;
  int i,j,k;
  int min=0,count=0;

  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&a[i]);

  for(i=0;i<n;i++){
    min=i;
    for(j=i;j<n;j++)
      if(a[j]<a[min])
	min=j;
    if(i!=min){
      swap(&a[i],&a[min]);
      count++;
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
