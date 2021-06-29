#include <stdio.h>

#define MAX 100

int main()
{
  int n,i,j,k,minj=0,invert=0,kazu=0;

  int A[MAX];

  scanf("%d",&n);

  for(k = 0;k < n;k++){

    scanf("%d",&A[k]);

  }

  for(i = 0;i <= n - 1;i++){

    minj = i;

  for(j = i;j <= n - 1;j++){

    if(A[j] < A[minj]){

      minj = j;
    }

  }

      invert = A[i];

      A[i] = A[minj];

      A[minj] = invert;

      if(A[i] != A[minj]){
        kazu = kazu + 1;
      }


}

for(k = 0;k < n;k++){

  if(k > 0) printf(" ");

  printf("%d",A[k]);

}

printf("\n");

printf("%d\n",kazu);

return 0;

}

