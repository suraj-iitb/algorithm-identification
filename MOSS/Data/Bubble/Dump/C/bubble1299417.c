#include <stdio.h>
#define N 100
#define swap(a,b) a^=b^=a^=b

int main(){

  int length, i, j, a[N], flag = 0;

  scanf("%d", &length);
  for(i = 0; i < length; i++) scanf("%d", &a[i]);

  for(i = 0; i < length - 1; i++){
    for(j = length - 1; j >= i + 1; j--){
      if(a[j] < a[j-1]){
	swap(a[j], a[j-1]);
	flag++;
      }
    }
  }

  for(i = 0; i < length; i++){
    printf("%d", a[i]);
    if(i != length - 1) printf(" ");
  }
  printf("\n%d\n", flag);

  return 0;
}
