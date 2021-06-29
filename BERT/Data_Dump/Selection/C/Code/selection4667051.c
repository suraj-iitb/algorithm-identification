#include<stdio.h>
#define MAX 100

int main(){
  int i, j, n, min, count=0, save;
  int A[MAX];

  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }

  for(i=0;i<n-1;i++){
    min = i;
    for(j=i;j<n;j++){
      if(A[j] < A[min]){
        min = j;
        
      }
    }
    if(min != i) count++;
    save = A[i];
    A[i] = A[min];
    A[min] = save;
  }

  for(j=0;j<n;j++){
    printf("%d", A[j]);
    if(j != n-1) printf(" ");
  }
  printf("\n%d\n", count);

  return 0;
}




