#include<stdio.h>
#define N 100

int main()
{
  int i, j, k, n, v, arr[N];

  while(1){
    scanf("%d", &n);
    if(n >= 1 || n <= 100) break;
  }

  for(i = 0; i < n; i++){
    scanf("%d", &arr[i]);
    if(arr[i] < 0 || arr[i] >1000) i--;
  }

  for(i = 0; i < n - 1; i++){
    printf("%d ", arr[i]);
  }
  printf("%d\n", arr[i]);

  for(i =1; i < n; i++){
    v = arr[i];
    j = i - 1;
    while(j >= 0 && arr[j] > v){
      arr[j + 1] = arr[j];
      j--;
    }

    arr[j + 1] = v;
    for(k = 0; k < n - 1; k++){
      printf("%d ", arr[k]);
    }
    printf("%d\n", arr[k]);
  }

  return 0;
}
