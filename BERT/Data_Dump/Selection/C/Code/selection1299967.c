#include <stdio.h>

main(){
  int i,j,k,l,f,a[100],c=0, min;

  scanf("%d", &k);
  for(i = 0;i < k;i++)scanf("%d", &a[i]);
  
  for(i = 0;i <= k - 1;i++){
    min = i;
    for(j = i;j <= k - 1;j++){
      if(a[j] < a[min]){
	min = j;
      }
    }
    l = a[i];
    a[i] = a[min];
    a[min] = l;
    if(i != min)c++;
  }
  for(i = 0;i < k-1;i++)printf("%d ", a[i]);
  printf("%d\n", a[i]);
  printf("%d\n", c);
  return 0;
}
