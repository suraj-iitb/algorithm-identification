#include <stdio.h>
#include <stdlib.h>
#define swap(a, b) {int t; t=a; a=b; b=t;}

int main()
{
  int *a;
  int n, i, flg=1, ans=0;
  scanf("%d", &n);
  a = (int *)malloc(sizeof(int)*n);

  for(i=0; i<n; i++){
    scanf("%d", a+i);
  }

  while(flg){
    flg=0;
    for(i=n-1; i>=1; i--){
      if(a[i-1] > a[i]){
        swap(a[i-1], a[i]);
        flg=1;
        ans++;
      }
    }
  }
  printf("%d", a[0]);
  for(i=1; i<n; i++){
    printf(" %d", a[i]);
  }
  printf("\n%d\n", ans);
  return 0;
}
  

        
