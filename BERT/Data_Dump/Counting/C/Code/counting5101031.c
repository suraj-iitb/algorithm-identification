#include <stdio.h>
#include <stdlib.h>

void Counting_Sort(int *, int *, int);

int n, c[10000];
int main(void){
  int i, k = 10000;
  int *a, *b;
  scanf("%d", &n);

  a = malloc(sizeof(int)*n);
  b = malloc(sizeof(int)*n);

  for(i=0; i<n; i++)
    scanf("%d", &a[i]);

  Counting_Sort(a, b, k);

  for(i=1; i<n; i++)
    printf("%d ", b[i]);
  printf("%d\n", b[i]);

  return 0;

}

void Counting_Sort(int a[], int b[], int k){
  int i, j;

  for(i=0; i<k; i++)
    c[i] = 0;

    for(j=0; j<n; j++)
      c[a[j]]++;

    for(i=1; i<k; i++)
      c[i] = c[i] + c[i-1];

    for(j=n-1; j>=0; j--){
      b[c[a[j]]] = a[j];
        c[a[j]]--;
    }
}

