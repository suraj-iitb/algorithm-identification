#include <stdio.h>
#define N 1000

void trace(int A[], int n){
  int i;
  for(i = 0; i < n; i++){
    if(i >= 1) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

main(){
  int i, j, n;
  int arr[N+1];
  int key;

  scanf("%d",&n);

  for(i = 0; i <= n; i++) scanf("%d", &arr[i]);

  trace(arr, n);

  for(i = 1; i < n; i++){
    key = arr[i];
    j = i-1;
    while(j >= 0 && arr[j] > key){
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
    trace(arr, n);
  }

  return 0;
}


