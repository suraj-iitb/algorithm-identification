#include<stdio.h>
main(){
  int n;
  int a[100];
  int i,j,k;
  int key;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    printf("%d",a[i]);
    if(i==n-1){
      printf("\n");
    }else{
      printf(" ");
    }
  }
  for(i=1;i<n;i++){
    key = a[i];
    j = i - 1;
    while(j >= 0 && a[j] > key){
      a[j+1] = a[j];
      j --;
    }
    a[j+1] = key;
    for(k=0;k<n;k++){
      printf("%d",a[k]);
      if(k==n-1){
        printf("\n");
      }else{
        printf(" ");
      }
    }
  }
}
