#include<stdio.h>

int main(){
  int a[10000],n,v,j,i;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=0;i<n;i++){

    v=a[i];
    j=i-1;
    while(j>=0&&a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    for(j=0;j<n-1;j++){
      printf("%d ",a[j]);
    }printf("%d",a[n-1]);
    printf("\n");
  }
}

