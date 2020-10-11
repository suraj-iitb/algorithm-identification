#include<stdio.h>

int main(){
  int i, j, n, a[128], ans=0, min, t;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }

  for(i=0; i<n-1; i++){
    min=i;
    for(j=i+1; j<n; j++){
      if(a[min]>a[j]){
	min=j;
      }
    }
    if(min!=i){
      t=a[min];
      a[min]=a[i];
      a[i]=t;
      ans++;
    }   
  }

  for(i=0; i<n; i++){
    if(i==n-1){
      printf("%d\n", a[i]);
    }else{
      printf("%d ", a[i]);
    }
  }
  printf("%d\n", ans);
  
  return 0;
}
