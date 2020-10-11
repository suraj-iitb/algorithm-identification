#include <stdio.h>
#include <stdlib.h>

#define N 2000001
#define k 10000

void countingSort(unsigned short *, unsigned short *);

int n;

int main(){
  unsigned short *a, *b;
  int c;
  scanf("%d",&n);

  a = malloc(sizeof(short)*n+1);
  b = malloc(sizeof(short)*n+1);
  
  for(c = 0; c < n; c++) scanf("%d",&a[c]);

  countingSort(a,b);

  for(c = 1; c < n; c++) printf("%d ",b[c]);
  printf("%d\n",b[c]);

  return 0;
}

void countingSort(unsigned short *x, unsigned short *y){
  int a;
  int z[k+1];
  for(a = 0; a < k+1; a++) z[a] = 0;
  for(a = 0; a < n; a++) z[x[a]]++;
  for(a = 1; a < k+1; a++) z[a] = z[a] + z[a-1];
  for(a = n-1; a >= 0; a--){
    y[z[x[a]]] = x[a];
    z[x[a]]--;
  }
}

