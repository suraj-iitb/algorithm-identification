#include <stdio.h>
#define N 100
#define swap(a,b) a^=b^=a^=b

int main(){

  int i, j, minj, flag = 0, length, a[N];
  
  scanf("%d", &length);
  for(i = 0; i < length; i++) scanf("%d",&a[i]);

  for(i = 0; i <= length - 1; i++){
    minj = i;
    for(j = i; j <= length - 1; j++){
	if(a[j] < a[minj]) minj = j;
      }
      if(a[i] != a[minj]){
	swap(a[i],a[minj]);
	flag++;
      }
    }

    for(i = 0; i < length; i++){
      printf("%d", a[i]);
      if(i != length - 1) printf(" ");
    }
    printf("\n%d\n", flag);

    return 0;

  }
