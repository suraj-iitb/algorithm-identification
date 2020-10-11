#include<stdio.h>

int main(){
  int n, a[1024], v;
  int i, j;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  for(i=1; i<n; i++){
    for(j=0; j<n; j++){
      if(j==n-1){
        printf("%d", a[j]);
      }else{
        printf("%d ", a[j]);
      }
    }
    printf("\n");
    
    v=a[i];
    j=i-1;
    while(j>=0 && a[j]>v){
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=v;
    
  }
  for(j=0; j<n; j++){
    if(j==n-1){
        printf("%d", a[j]);
    }else{
      printf("%d ", a[j]);
    }
  }
  printf("\n");
  
  return 0;
}
