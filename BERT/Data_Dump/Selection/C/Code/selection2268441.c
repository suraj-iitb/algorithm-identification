#include <stdio.h>
#include <stdlib.h>

int main()
{
  int N, i, key, j, k = 0, minj;
  int *data;

  scanf("%d", &N);

  data = (int *)malloc(N * sizeof(int));

  for(i = 0; i < N; i++) scanf("%d", &data[i]);

  for(i = 0; i < N; i++){
   
    minj = i;
    
    for(j = i; j < N; j++){
      if(data[j] < data[minj]){
	minj = j;
      }
    }
     key = data[minj];
    data[minj] = data[i];
    data[i] = key;
    if(data[i] != data[minj]) k++; 
  }
  for(i = 0; i < N - 1; i++) printf("%d ", data[i]);
  printf("%d\n", data[i]);
  printf("%d\n", k);
 
  return 0;
}
