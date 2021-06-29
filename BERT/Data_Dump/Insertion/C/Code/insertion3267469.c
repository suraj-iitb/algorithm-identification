#include <stdio.h>

int main(){
  int n,i=0,b;

  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }

  for(i=1;i<=n-1;i++){
    printf("%d",a[0]);
    for(b=1;b<n;b++){
      printf("% d",a[b]);
    }
    printf("\n");
    int v=a[i];
    int j=i-1;
    while(j>=0 && a[j] > v){
      a[j+1]=a[j];
      j--;
      a[j+1]=v;
    }
  }
  printf("%d",a[0]);
  for(b=1;b<n;b++){
    printf(" %d",a[b]);
  }
  printf("\n");

  return 0;
}

