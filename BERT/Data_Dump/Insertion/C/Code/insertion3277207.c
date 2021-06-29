#include<stdio.h>

int main(){
  int a[1000];
  int i,j,n,key;
  
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  for(i=0;i<n;i++){
    printf("%d",a[i]);
    if(i!=n-1) printf(" ");
  }
  printf("\n");
  for(i=1;i<n;i++){
    key=a[i];
    j=i-1;
    while(j>=0&&a[j]>key){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=key;
    for(j=0;j<n;j++){
      printf("%d",a[j]);
      if(j!=n-1) printf(" ");
    }
      printf("\n");
    }
    return 0;
  }

