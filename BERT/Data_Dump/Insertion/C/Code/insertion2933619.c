#include <stdio.h>
#include <stdlib.h>
#define N 100
#define A 1000
int main(){
  int i,j,k,n;
  int a[A];
  int key;
  scanf("%d",&n);
  for(i = 0;i <= n-1; i++){
    scanf("%d",&a[i]); 
  }
  for(k=0;k <= n-1 ;k++){
    if(k==n-1){
      printf("%d\n",a[k]);
    }
    else{
      printf("%d ",a[k]);
    }
  }
  for(i=1;i <= n-1; i++){
    key = a[i];
    j = i-1;
    while(j >= 0 && a[j] > key){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=key;
    for(k=0;k<=n-1;k++){
      if(k==n-1){
	printf("%d\n",a[k]);
      }
      else{
	printf("%d ",a[k]);
      }
    }
  }
  return 0;
}
    


