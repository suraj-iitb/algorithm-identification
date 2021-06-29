#include <stdio.h>
#define N 100
int main(){
  int a[N];
  int x,i,j,minj,c=0,d;
  scanf("%d",&x);
  for(i=0;i<x;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<x;i++){
    minj=i;
    for(j=i;j<x;j++){
      if(a[j]<a[minj]){
	minj=j;
      }
    }
    if(a[i]!=a[minj]){
      d=a[i];
      a[i]=a[minj];
      a[minj]=d;
      c++;
    }
  }
  for(i=0;i<x-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n%d\n",a[i],c);
  return 0;
}
