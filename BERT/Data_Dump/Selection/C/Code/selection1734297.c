#include <stdio.h>

int swap(int *p1, int *p2, int n){
  int pool;

  pool = *p1;
  *p1 = *p2;
  *p2 = pool;

  return n+1;
}

int main(){
  int n,i,j,min,count=0;
  int *parr;

  // input and allocation
  scanf("%d",&n);
  parr = (int *)malloc(sizeof(int) * n);
  for(i=0; i<n; i++) scanf("%d",&parr[i]);

  // sorting
  for(i=0; i<n; i++){
    min = i;
    for(j=i; j<n; j++){
      if(parr[j] < parr[min]) min = j;
    }
    if(min == i) continue;
    count = swap(&parr[i],&parr[min],count);
  }

  // output
  for(i=0; i<n; i++){
    printf("%d",parr[i]);
    if(i == n-1) break;
    printf(" ");
  }
  printf("\n%d\n",count);

  free(parr);

  return 0;
}
