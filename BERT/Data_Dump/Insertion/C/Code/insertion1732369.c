#include<stdio.h>

int main(){
  int n,i,j,v,a[100];
  scanf("%d",&n);

  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
  }

  for(j = 0;j < n;j++){
    if(j == n - 1){
      printf("%d",a[j]);
    }
    else{
      printf("%d ",a[j]);
    }
  }
  printf("\n");

  for(i = 1;i <= n - 1;i++){
    v = a[i];
    j = i - 1;

    while(j >= 0 && a[j] > v){
      a[j+1] = a[j];
      j--;
      a[j+1] = v;
    }

    for(j = 0;j < n;j++){
      if(j == n - 1){
	printf("%d",a[j]);
      }
      else{
	printf("%d ",a[j]);
      }
    }
   printf("\n");
  }
  return 0;
}
