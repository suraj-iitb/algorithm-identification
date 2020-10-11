#include <stdio.h>
#include <stdlib.h>

int n;

void countingSort(int*, int*, int);  

int main() {
  int *a, *b;
  int i, max = 0;

  scanf("%d",&n);
  a = (int*)malloc(sizeof(int)*(n+1));
  b = (int*)malloc(sizeof(int)*(n+1));
  for(i = 1;i <= n;i++) { 
    scanf("%d",&a[i]);
    if(max < a[i])
      max = a[i];
  }
  countingSort(a, b, max);
  for(i = 1;i <= n;i++) { 
    printf("%d", b[i]);
    if(i != n) 
      printf(" "); 
  }
  printf("\n");
  return 0;
}

void countingSort(int* a,int* b, int k) {
  int i, j, c[k+1];
  for(i = 0;i <= k;i++) 
    c[i] = 0;
  
  for(j = 1;j <= n;j++)
    c[a[j]]++;

  for(i = 1;i <= k;i++)
    c[i] += c[i-1];

  for(j = n;j > 0;j--) {
    b[c[a[j]]] = a[j];
    c[a[j]]--;
  }  
}
