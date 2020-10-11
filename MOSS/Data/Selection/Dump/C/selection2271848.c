#include <stdio.h>
#define N 100

int main() {

  int i, j, n, min, temp, count=0;
  int num[N];
  
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &num[i]);
  }

  for(i=0; i<n; i++){
    min = i;
    for(j=i; j<n; j++){
      if(num[j] < num[min]){
	min = j;
      }
    }
    if(i != min){
    temp = num[i];
    num[i] = num[min];
    num[min] = temp;
    count++;
    }
  }

  for(i=0; i<n; i++){
    printf("%d", num[i]);
    if(i==n-1) break;
    printf(" ");
  }
  printf("\n");
  printf("%d\n", count);

  return 0;
}
