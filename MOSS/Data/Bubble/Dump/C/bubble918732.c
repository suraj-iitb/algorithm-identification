#include<stdio.h>
#define N 100
void swap(int *, int *);

int main(void){
  int i, j, n, a[N], c=0;
  scanf("%d", &n);
  for(i=0; i < n; i++) scanf("%d", &a[i]);
  for(i=0; i < n; i++){
    
    for(j = n - 1; j > i; j--){
      if(a[j] < a[j-1]){
	swap(&a[j],  &a[j-1]);
	  c++;
      }
    }
  printf("%d", a[i]);
  if(i < n-1) printf(" ");
  }

  printf("\n%d\n", c);
  return 0;
}

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
