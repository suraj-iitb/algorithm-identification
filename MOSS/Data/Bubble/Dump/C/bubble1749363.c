#include <stdio.h>
#define N 100

int main(){
  int i, j, n, tmp, arr[N], flag = 1, count = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }

  while(flag){
    flag = 0;
    for(i = n - 1; i > 0; i--){
      if(arr[i] < arr[i - 1]){
	tmp = arr[i];
	arr[i] = arr[i - 1];
	arr[i - 1] = tmp;
	flag = 1;
	count++;
      }
    }
  }

  for(i = 0; i < n - 1; i++){
    printf("%d ", arr[i]);
  }
  printf("%d\n%d\n", arr[i], count);

  return 0;
}  
