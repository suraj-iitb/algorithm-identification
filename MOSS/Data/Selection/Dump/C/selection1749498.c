#include <stdio.h>
#define N 100

int main(){
  int i, j, n, arr[N], tmp, minj, count = 0;
  
  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
  
  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(arr[j] < arr[minj]) minj = j;
    }

    if(minj != i){
      tmp = arr[i];
      arr[i] = arr[minj];
      arr[minj] = tmp;
      count++;
    }
  }
  
  for(i = 0; i < n - 1; i++){
    printf("%d ", arr[i]);
  }
  printf("%d\n%d\n", arr[i], count);
  
  return 0;
}
