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
      if(a[min] > a[j])
        min = j;
    }
    
    if(i != min){
      swap = a[min];
      a[min] = a[i];
      a[i] = swap;
    
      ans++;
    }
  }
  
  for(i = 0; i < n-1; i++)
    printf("%d ", a[i]);
    
  printf("%d\n", a[n-1]);
  
  printf("%d\n", ans);

    return 0;
}
