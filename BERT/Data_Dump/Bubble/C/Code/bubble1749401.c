#include <stdio.h>
#define N 100
 
int main(){
  int i, j, n, temp, arr[N], flag = 1, cnt = 0;
 
  scanf("%d", &n);
 
  for(i = 0; i < n; i++){
    scanf("%d", &arr[i]);
  }
 
  while(flag){
    flag = 0;
    for(i = n - 1; i > 0; i--){
      if(arr[i] < arr[i - 1]){
    temp = arr[i];
    arr[i] = arr[i - 1];
    arr[i - 1] = temp;
    flag = 1;
    cnt++;
      }
    }
  }
 
  for(i = 0; i < n - 1; i++){
    printf("%d ", arr[i]);
  }
  printf("%d\n%d\n", arr[i], cnt);
 
  return 0;
}  
