#include<stdio.h>
#define N 100
void swap(int *x, int *y);
int main(){
  int n,i,j,count=0,a[N];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n-1;i++){
    for(j=n-1;j>=i+1;j--){
      if(a[j]<a[j-1]){
	swap(a+j,a+(j-1));
	count++;
      }
    }
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
  z= *x;
  *x=*y;
  *y=z;
}
