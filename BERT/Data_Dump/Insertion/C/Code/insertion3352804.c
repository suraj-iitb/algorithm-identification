#include<stdio.h>

// This function behave as Outpuetter.
void trace(int A[], int n){
  int i;
  for ( i = 0; i < n; i++ ){
    if ( i > 0 ) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

int main(void){
  int len, i, j;
  scanf("%d", &len);
  int a[len];

  // input data.
  for (i=0;i<len;i++) scanf("%d", &a[i]);

  int tmp;
  for(i=0;i<len;i++){
    tmp = a[i];
    j = i;
    while(j>0 && a[j-1]>tmp){
      a[j] = a[j-1];
      j--;
    }
    a[j] = tmp;
    trace(a, len);
  }
  return 0;
}

