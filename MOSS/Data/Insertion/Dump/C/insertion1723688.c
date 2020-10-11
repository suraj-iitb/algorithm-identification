#include <stdio.h>

int main(){
  int data[100];
  int i,j,n,key;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&data[i]);
  }
  
  for(j=0;j<n-1;j++){
    printf("%d ",data[j]);
  }
  printf("%d",data[j]);
  printf("\n");
  
  for(i=1;i<n;i++){
    key = data[i];
    j = i-1;
    while(j>=0 && key < data[j]){
      data[j+1] = data[j];
      j--;
      data[j+1] = key;
    }

    for(j=0;j<n-1;j++){
      printf("%d ",data[j]);
    }
    printf("%d",data[j]);
    printf("\n");
  }
  return 0;
}
