#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, key = 0, k = 0, i, j, flag;
  int *data;

  scanf("%d", &n);

  data = (int *)malloc(n * sizeof(int));

  for(i = 0; i < n; i++) scanf("%d", &data[i]);

  flag = 1;
  while(flag){
    flag = 0;
    for(i = n - 1; i >= 1; i--){
      if(data[i] < data[i - 1]){
	key = data[i - 1];
	data[i - 1] = data[i];
	data[i] = key;
	flag = 1;
	k++;
      }
    }
  }
  for(i = 0; i < n - 1; i++) printf("%d ", data[i]);

  printf("%d\n", data[n - 1]);
  printf("%d\n", k);

  return 0;
}
