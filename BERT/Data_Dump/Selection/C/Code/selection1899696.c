#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n;
  int i,j;
  int k=0;
  int *a;
  int minj;
  int temp;
  
  scanf("%d",&n);
  
  a = (int *)malloc(sizeof(int) *n);

  for(i=0; i<n; i++){
    scanf("%d",&a[i]);
  }

  for(i=0; i<n; i++){
    minj = i;
    for(j=i; j<n; j++){
      if(a[j] < a[minj]){
	minj = j;
      }
    }
    temp = a[i];
    a[i] = a[minj];
    a[minj] = temp;
    if(i != minj){
      k++;
    }
  }

  for(i=0; i<n; i++){
    printf("%d",a[i]);
    if(i != (n-1)){
      printf(" ");
    }
  }
  printf("\n%d\n",k);
  
  free(a);
  
  return(0);
}
