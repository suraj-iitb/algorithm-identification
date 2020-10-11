#include<stdio.h>
#define N 100

int main(){
  int n, flag=0, i, j;
  int A[N+1];
  int key;
  scanf("%d", &n);

  for ( i = 1; i <= n; i++ ) scanf("%d", &A[i]);

  for(j=2; j<=n; j++){
    key = A[j];
    i = j-1;

    while(i>0 && A[i]>key){
      A[i+1] = A[i];
      i = i-1;
      A[i+1] = key;
      flag++;
    }
  }

  for(i=1; i<=n; i++){
    if(i>1) printf(" ");
    printf("%d",A[i]);
  }

  printf("\n%d\n",flag);

  return 0;
}
