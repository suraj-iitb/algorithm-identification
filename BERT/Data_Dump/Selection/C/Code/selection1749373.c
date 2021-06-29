#include <stdio.h>
int main(){
  int i, j, n, minj, cnt = 0, tmp;
  int a[100];

  scanf("%d", &n);
  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(a[j] < a[minj])
        minj = j;
    }
    if(i != minj){
      tmp = a[i];
      a[i] = a[minj];
      a[minj] = tmp;
      cnt++;
    }
  }

  for(i = 0; i < n-1; i++)
    printf("%d ", a[i]);
  printf("%d\n", a[i]);
  printf("%d\n", cnt);
  
  return 0;
}
