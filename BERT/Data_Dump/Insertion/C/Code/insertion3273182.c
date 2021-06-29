#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, i, k, j, key = 0;
  int *data;

  scanf("%d", &n);

  data = (int *)malloc(n * sizeof(int));

  for(i = 0; i < n; i++)
    scanf("%d", &data[i]);

  for(k = 0; k < n; k++){
    if(k != 0)
      printf(" ");
    printf("%d", data[k]);

  }

  //printf("\b");

  printf("\n");
  
  /*ここからが挿入ソート*/
  for(i = 1; i < n; i++){    
    key = data[i];
    j = i - 1;
    
    while(j  >= 0 && data[j] > key){
      data[j + 1] = data[j];
      j = j - 1;
    }

    data[j + 1] = key;

    for(k = 0; k < n; k++){
      if(k != 0)
	printf(" ");
      printf("%d", data[k]);

    }
      
    //printf("\b");
    printf("\n");
  }
  
  return 0;
}



