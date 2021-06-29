#include <stdio.h>
main(){
  int i, j, c = 0, f, k;
  int r[100];

  scanf("%d", &k);
  
  for(i = 0;i < k;i++){
    scanf("%d", &r[i]);
  }

  f = 1;
  while(f){
    f = 0;
      for(j=k-1;j>=1;j--){
        if(r[j] < r[j-1]){
          i = r[j-1];
          r[j-1] = r[j];
          r[j] = i;
          f = 1;
          c++;
        }
      }

  }
  for(i = 0;i < k-1;i++){
    printf("%d ", r[i]);
  }
  printf("%d\n", r[i]);
  printf("%d\n", c);
  return 0;
}
