#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) {int t; t=a; a=b; b=t;}
 
int main()
{
  int *a;
  int n, i, j, min, ans=0;
  scanf("%d", &n);
  a = (int *)malloc(sizeof(int)*n);
   
  for(i=0; i<n; i++){
    scanf("%d", a+i);
  }
 
  for(i=0; i<n-1; i++){
    min=i;
    for(j=i; j<n; j++){
      if(a[min] > a[j]) min=j;
    }
    if(min != i){
      swap(a[i], a[min]);
      ans++;
    }
  }
  printf("%d", a[0]);
  for(i=1; i<n; i++){
    printf(" %d", a[i]);
  }
  printf("\n%d\n", ans);
  return 0;
}
