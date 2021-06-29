#include<stdio.h>

int main(){
  int n,i,j,k,v,a[1000];

  scanf("%d",&n);
  for(k = 0;k < n;k++){
    scanf("%d",&a[k]);
    if(k<n-1){
      printf("%d ",a[k]);
    }
    else if(k==n-1){
      printf("%d",a[k]);
    }
    
  }
  printf("\n");
  for(i = 1;i < n;i++){
    v = a[i];
    j = i-1;
    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
      a[j+1] = v;
    }
    for(k = 0;k < n;k++){
      if(k<n-1){
	printf("%d ",a[k]);
      }
      else if(k==n-1){
	printf("%d",a[k]);
      }
    }
    
    printf("\n");
  }
  
  return 0;
}
