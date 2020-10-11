#include<stdio.h>
#define N 100
void swap(int *x, int *y);
int main(){
  int n,i,j,a[N],min,count=0,flag=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<=n-2;i++){
    min=i;
    for(j=i;j<=n-1;j++){
      if(a[j]<a[min]){
	min=j;
	flag=1;
      }
    }
    if(flag==1){
      count++;
      flag=0;
    }
    swap(a+i,a+min);
  }
  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[n-1]);
  printf("%d\n",count);
  return 0;
}

void swap(int *x,int *y){
  int z;
  z=*x;
  *x=*y;
  *y=z;
}
