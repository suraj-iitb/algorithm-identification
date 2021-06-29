#define N 100
#include <stdio.h>
int main(){
  int i,j,k,a[N],n,v;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=1;i<n+1;i++){
    for(k=0;k<n-1;k++){
      printf("%d ",a[k]);
    }
    printf("%d",a[n-1]);
    printf("\n");
    
    v = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > v){
      
      a[j+1] = a[j];
      j--;      
    }
    a[j+1] = v;
  }
  return 0;
}
