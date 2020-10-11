#include<stdio.h>

int main(){
  int i, j, n, a[100], minj, temp, cnt=0;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &a[i]);

  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(a[j] < a[minj]) {
        minj = j;
      }
    }
    if(i != minj) cnt++;
    temp = a[i];
    a[i] = a[minj];
    a[minj] = temp;
  }
  
  for(i = 0; i < n; i++){
      printf("%d", a[i]);
      if(i < n-1) printf(" ");
      else printf("\n%d\n", cnt);
  }
  return 0;
}

