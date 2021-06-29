#include <stdio.h>
#define N 100

int main(){
  int flag = 1;
  int i, j, k, b, n, con = 0;
  int a[N];

  scanf("%d", &b);

  for(i = 0; i < b; i++){
    scanf("%d", &a[i]);
  }
  i = 0;
  while(flag){
    flag = 0;
    for(j = b-1; j >= i+1; j--){
      if(a[j] < a[j-1]){
	n = a[j];
	a[j] = a[j-1];
	a[j-1] = n;
	flag = 1;
	con = con + 1;
      }
    }
    i++;
  }

  printf("%d", a[0]);
  for(k = 1; k < b; k++){
    printf(" %d", a[k]);
  }
  printf("\n%d\n", con);

  return 0;
}

