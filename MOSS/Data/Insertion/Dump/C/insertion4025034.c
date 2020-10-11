#include<stdio.h>
#include<stdlib.h>

int main(){
  int i,j,n,*a,key;
  scanf("%d",&n);
  a=malloc(4*n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(i=0;i<n-1;i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]);
  
  for(i=1;i<n;i++){
    key=a[i];
    j=i-1;
    while(j>=0 && a[j]>key){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=key;
    for(j=0;j<n-1;j++){
      printf("%d ",a[j]);
    }
    
      printf("%d\n",a[j]);
    
  }
  return 0;
}


