#include <stdio.h>

int main(){
  int a[100]={0},n,i,j,key;
  scanf("%d",&n);
  for(i=0; i<n; i++) scanf("%d",&a[i]);
  for(j=0; j<n-1; j++){
      printf("%d ",a[j]);
    }
  printf("%d\n",a[j]);
  for(i=1; i<n; i++){
    key=a[i];
    j=i-1;
    while(j>=0 && a[j]>key){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=key;
    for(j=0; j<n-1; j++){
      printf("%d ",a[j]);
    }
    
    printf("%d\n",a[j]);
  }
  return 0;
}

