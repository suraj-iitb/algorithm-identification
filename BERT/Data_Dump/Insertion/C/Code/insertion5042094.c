#include <stdio.h>

int main(){
  int element,i,j,key;
  int arr[100];
  scanf("%d",&element);
  for(i=1;i<=element;i++){
    scanf("%d",&arr[i]);
  }

  for(j=1;j<=element;j++){
    key = arr[j];
    i = j-1;
    while(i>0 && key<arr[i]){
      arr[i+1] = arr[i];
      i--;
    }
    arr[i+1]=key;
    for(i=1;i<element;i++){
      printf("%d ",arr[i]);
    }
    printf("%d",arr[element]);
    printf("\n");
  }
  return 0;
}
