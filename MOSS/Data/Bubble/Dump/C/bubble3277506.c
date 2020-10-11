#include<stdio.h>

int main() {
  int i, j, a[1000], n, temp, cnt=0;

  scanf("%d", &n);
  for(i = 0; i < n; i++) scanf("%d", &a[i]);

  for(i = 0; i < n; i++){
    for(j = n - 1; j != i; j--){
      if(a[j] < a[j - 1]){
        temp = a[j];
        a[j] = a[j-1];
        a[j-1] = temp;
	cnt++;
      }
    }
  }
  for(i = 0; i < n; i++){
      printf("%d", a[i]);
      if(i < n-1) printf(" ");
      else printf("\n%d\n", cnt);
  }
  return 0;
}

