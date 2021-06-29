#include <stdio.h>

#define N 500000

void mergeSort(int *,int, int);
void merge(int *,int, int, int);

int count = 0;

int main (void) {

  int a,b[N],i;

   scanf("%d",&a);
  for(i = 0; i < a; i++)
    scanf("%d",&b[i]);

  mergeSort(b,0,a - 1);


  for (i = 0; i < a-1; i++)
    printf("%d ", b[i]);
  printf("%d",b[a-1]);
  printf("\n");
  printf("%d\n",count);
  return 0;
}


void merge(int b[], int l, int m, int r) {
  int i, j, k;

    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1];
    int R[n2];

    for (i = 0; i < n1; i++)
      L[i] = b[l + i];
    for (j = 0; j < n2; j++)
      R[j] = b[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
          b[k] = L[i];
          i++;
          count++;
        } else{
b[k] = R[j];
          j++;
          count++;
        }
        k++;
    }

    while (i < n1) {
      b[k] = L[i];
        i++;
        k++;
        count++;
    }

    while (j < n2) {
      b[k] = R[j];
        j++;
        k++;
        count++;
    }
}

void mergeSort(int b[], int l, int r) {

  if (l < r) {
      int m = (l + r) / 2;

      mergeSort(b, l, m);
      mergeSort(b, m + 1, r);
 merge(b, l, m, r);
    }

}        

