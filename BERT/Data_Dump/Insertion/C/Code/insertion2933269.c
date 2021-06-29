#include <stdio.h>

int main(){
  int i,j,k,l,key;
  int a[100];

  scanf("%d",&l);
  for(i=0; i<l; i++)
    scanf("%d",&a[i]);

  for(k=0; k<l-1; k++)
      printf("%d ",a[k]);
    printf("%d\n",a[k]);

  for(i=1; i<l; i++){
    key = a[i];
    j = i-1;
    while(j>=0 && a[j]>key){
      a[j+1] = a[j];
      j--;
    }
    a[j+1]=key;
    for(k=0; k<l-1; k++)
      printf("%d ",a[k]);
    printf("%d\n",a[k]);
  }
  return 0;
}
  

  

