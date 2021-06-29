#include <stdio.h>

#define N 100

int main()
{
  int i, j, n, v, ct;
  int array[N];

  scanf("%d", &n);

  for( ct=0; ct<n; ct++){
    scanf("%d", &array[ct]);
  }   

  for( ct=0; ct<n-1; ct++){
    printf("%d ", array[ct]);
  }
  printf("%d\n", array[n-1]);

  for( i=1; i<=n-1; i++){
    v = array[i];

    j = i - 1;

    while( j >= 0 && array[j] > v ){
      array[j+1] = array[j];

      j--;
    }

    array[j+1] = v;

    for( ct=0; ct<n-1; ct++){
      printf("%d ", array[ct]);
    }
    printf("%d\n", array[n-1]);

  }

  return 0;
}
