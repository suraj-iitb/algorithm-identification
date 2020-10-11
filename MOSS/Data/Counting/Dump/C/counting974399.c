#include<stdio.h>
#define N 2000000
void counting_sort(int);

int B[N + 1];
int A[N + 1];
int length;
int print(int j){
  int max, i;
  max = 0; 
  for(i = 1; i <= j; i++){
    scanf("%d", &A[i]);
    if(max < A[i]){
      max = A[i];
    }
  }
  return max;
}
main(){
  int i, max;
  scanf("%d", &length);
  
  max = print(length);

  counting_sort(max);

  for(i = 1; i <= length; i++){
    printf("%d", B[i]);
    if(i != length) printf(" ");
  }
  printf("\n");
  return 0;
}

void counting_sort(int k){
  int i, j, a;
  int C[k + 1];

  for(i = 0; i < k + 1; i++){
    C[i] = 0;
  } 

  for(j = 1; j < length + 1; j++){
    i = A[j];
    C[i]++;
  } 

  for(i = 1; i < k + 1; i++){
    C[i] += C[i - 1];
  }
  
  for(j = length; j > 0; j--){
    i = A[j];
    a = C[i];
    B[a] = A[j];
    C[i]--;
  }

}
