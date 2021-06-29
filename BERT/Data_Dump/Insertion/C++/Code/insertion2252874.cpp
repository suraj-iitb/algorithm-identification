#include <stdio.h>

int main(){

  int array[124] = {};
  int i,j,v = 0,n,k;
  scanf("%d",&n);
  
  for(i = 0;i < n;i++){
    scanf("%d",&array[i]);
  }

  for(i = 1;i <= n;i++){
    v = array[i];
    j = i - 1;
    for(k = 0;k < n;k++){
      if (k != n - 1) printf("%d ",array[k]);
      else printf("%d",array[k]);
    }
    printf("\n");
    
    while(j >= 0 && array[j] > v){
      array[j + 1] = array[j];
      j--;
      array[j + 1] = v;
    }
  }

  return 0;
}
