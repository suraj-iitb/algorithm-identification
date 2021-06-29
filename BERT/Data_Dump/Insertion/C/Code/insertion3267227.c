#include <stdio.h>

int main(){
  int i,j;
  int n,a;

  scanf("%d",&n);
  int data[n];
  for(i = 0;i < n;i++){
    scanf("%d",&a);
    data[i] = a;
  }

  for(j = 0;j < n;j++){
    int key = data[j];
    i = j -1;
    while(i>=0 && data[i] > key){
      data[i+1] = data[i];
      data[i] = key;
      i = i-1;
    }
    for(i = 0;i < n;i++){
    printf("%d",data[i]);
    if(i==n-1) break;
    printf(" ");
    }
  printf("\n");
  }
   
  return 0;
}

