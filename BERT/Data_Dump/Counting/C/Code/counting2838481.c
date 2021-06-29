#include <stdio.h>
#define K 10000
int numbers[2000005];
int sortedNums[2000005];
void printArray(int *array, int n){
  for(int i = 0; i < n; ++i){
    printf("array[%d]: %d\n", i, array[i]);
  }
}
void countingSort(int n){
  int C[K];
  for(int i = 0; i <= K; ++i){
    C[i] = 0;
  }
  for(int i = 0; i < n; ++i){
    ++C[numbers[i]];
  }
  for(int i = 1; i <= K; ++i){
    C[i] = C[i] + C[i - 1];
  }
  for(int i = 0; i < n; ++i){
    sortedNums[C[numbers[i]] - 1] = numbers[i];
    --C[numbers[i]];
  }
}
int main(){
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; ++i){
    scanf("%d", &numbers[i]);
  }
  countingSort(n);

  for(int i = 0; i < n; ++i){
    printf("%d", sortedNums[i]);
    if(i != n - 1)
      printf(" ");
  }
  printf("\n");
  return 0;
}

