#include <stdio.h>
#include <stdlib.h>

int main(){

  int n,i,j,k,key;
  int *a;

  scanf("%d",&n);

  a = malloc(sizeof(int)*n);
  
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  
  
  for(i=1;i<n+1;i++){
    for(k=0;k<n;k++){
      printf("%d",a[k]);
      if(k==n-1)printf("\n");
      else     printf(" ");
    }
    
    key = a[i];
    j = i - 1;
    
    while( j >= 0 && a[j] > key){
      a[j+1] = a[j];
      j--;
      a[j+1] = key;
    }
  }
  


  return 0;
}

