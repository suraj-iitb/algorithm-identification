#include <stdio.h>

#define N 100

int main(){
  int a[N],n,i,j,t,min,count=0;
  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&a[i]);
  for(i=0; i<n-1; i++){
    min=i;
    for(j=i+1; j<n; j++){
      if(a[j]<a[min]) min=j;
    }
    if(i!=min){
      t=a[i];a[i]=a[min];a[min]=t;
      count++;
    }
  }
  for(i=0; i<n-1; i++) printf("%d ",a[i]);
  printf("%d\n",a[i]);
  printf("%d\n",count);
  return 0;
}

