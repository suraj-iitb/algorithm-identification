#include<stdio.h>

int selectionSort(int a[], int N){
  int i, j, temp, minj;
  int sw = 0;

  for (i=0; i<N-1; i++) {
    minj = i;
    for (j=i; j<N; j++) {
      if (a[j] < a[minj])
        minj = j;
    }
    temp    = a[i];
    a[i]    = a[minj];
    a[minj] = temp;
    if (i != minj)
      sw++;
  }
  return sw;
}

int main(){
  int a[100], N, i, sw;

  scanf("%d", &N);
  for (i=0; i<N; i++)
    scanf("%d", &a[i]);

  sw = selectionSort(a, N);

  for (i=0; i<N; i++) {
    if (i>0)
      putchar(' ');
    printf("%d", a[i]);
  }
  printf("\n%d\n", sw);

  return 0;
}
