#include <stdio.h>

int main(void){
  int N;
  int a[1000];
  int i, j, key;

  scanf("%d",&N);
  for(i=0;i<N;i++){
    scanf("%d",&a[i]);
    printf("%d",a[i]);
    if(i<N-1) printf(" ");
  }

  printf("\n");

  for(i=1;i<=N-1;i++){
    key = a[i];
    j = i - 1;
    while(j>=0 && a[j]>key){
      a[j+1] = a[j];
      j--;
    }
    
    a[j+1] = key;
    
    for(j=0;j<N;j++){
      printf("%d",a[j]);
      if(j < N-1) printf(" ");
    }
    printf("\n");

  }
  return 0;
}


