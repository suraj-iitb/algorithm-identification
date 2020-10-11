#include <stdio.h>

int main(){
  int a[1000];
  int n,i,j,alt;

  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&a[i]);

  
  for(i=0;i<n;i++){
    alt=a[i];
    j=i-1;
    while(j>=0&&a[j]>alt){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=alt;
    for(j=0;j<n-1;j++){
      printf("%d ",a[j]);
    }
    printf("%d\n",a[j]);
  }

  return 0;
}
