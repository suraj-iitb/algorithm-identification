#include <stdio.h>

void output(int A[], int n){
  int i;
  for (i = 1; i < n+1; i++){
    printf("%d", A[i]);
    if(i < n)printf(" ");
    else  printf("\n");
  }

}

int main(){
  int A[1000];
  int n, i, j, v;

  scanf("%d", &n);

  for(i = 1; i <= n; i++){
    scanf("%d", &A[i]); 
  }


  
  for(i = 1; i <= n; i++){
    v = A[i];
    j = i - 1;

    while(j >= 0 && A[j] > v){
      A[j+1] = A[j];
      j--;
    }
    
    A[j+1] = v;
    output(A, n);
  }

  return 0;
}
