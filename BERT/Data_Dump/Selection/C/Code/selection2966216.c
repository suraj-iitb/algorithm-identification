#include <stdio.h>

int main(){
  int i,j,minj,n,a[100],count=0,x;

  scanf("%d",&n);
  for(i=0;i < n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i < n-1;i++){
    minj=i;
    for(j=i;j <= n-1;j++){
      if(a[j] < a[minj]){
	minj=j;
      }
    }
    if(minj != i){
      x=a[i];
      a[i]=a[minj];
      a[minj]=x;
      count++;
    }
  }
  for(i=0;i < n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]);
  printf("%d\n",count);
  return 0;
}

