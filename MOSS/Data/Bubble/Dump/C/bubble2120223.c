#include <stdio.h>
#include <stdlib.h>

int BubbleSort(int *a, int n);

int main(void){
  int i, n, *a, ans;

  scanf("%d", &n);
  a = (int *)malloc(sizeof(int) * n);
  if(a == NULL){
    printf("?????¢????¢??????¨??????\n");
    return -1;
  }
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  ans = BubbleSort(a, n);
  for(i = 0; i < n; i++){
    printf("%d", a[i]);
    if(i < n-1){
      printf(" ");
    }
  }
  printf("\n%d\n", ans);
  free(a);
  return 0;
}


int BubbleSort(int *a, int n){
  int flag, i, j, temp, count = 0;

  for(i = n; i > 0; i--){
    flag = 0;
    for(j = 1; j < i; j++){
      if(a[j-1] > a[j]){
	temp = a[j-1];
	a[j-1] = a[j];
	a[j] = temp;
	count++;
	flag = 1;
      }
    }
    if(flag == 0)  break;
  }
  return count;
}
