#include <stdio.h>

int main()
{
  int i, j, n, a[100], min, swap, ans = 0;
  
  scanf("%d", &n);
  
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);
    
  for(i = 0; i < n-1; i++){
  	min = i;
    for(j = i; j < n; j++){
      if(a[j] < a[min])
        min = j;
    }
    for(j = min; j > i; j--){
      swap = a[j];
      a[j] = a[j-1];
      a[j-1] = swap;
      
      ans++;
    }
  }
  
  for(i = 0; i < n-1; i++)
    printf("%d ", a[i]);
    
  printf("%d\n", a[n-1]);
  
  printf("%d\n", ans);

    return 0;
}
