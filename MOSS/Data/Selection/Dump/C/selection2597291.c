#include<stdio.h>

int SelectionSort(int a[],int n){
  int i, j, minj, v, cw = 0;
  for( i = 0; i < n - 1; i++){
    minj = i;
    for( j = i; j < n; j++){
      if (a[j] < a[minj])minj = j;
    }
    v = a[i]; a[i] = a[minj]; a[minj] = v;
    if ( i != minj ) cw++;
  }
  
  for( i = 0; i < n; i++){
    if (i > 0)
      printf(" ");
    printf("%d",a[i]);
  }
  
  printf("\n%d\n",cw);
  return 0;
}

int main(){
  int n, i;
  int a[100];
  
  scanf("%d", &n);
  for( i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  SelectionSort(a, n);
  
  return 0;
}
