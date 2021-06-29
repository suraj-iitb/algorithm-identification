#include <stdio.h>
int main(void){
  int i,j;
  int n,a[100];
  int v;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%d",&a[i]);
  for(i=0;i<n;i++){
    v=a[i];
    j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    printf("%d",a[0]);
    for(j=1;j<n;j++) printf(" %d",a[j]);  
    printf("\n");
  }
  return(0);
}
  
