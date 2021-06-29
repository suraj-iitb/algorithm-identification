#include <stdio.h>
#define N 20000

int main(){

  int i, j, n, flag, temp, count=0;
  int num[N];

  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &num[i]);
  }
  
  flag = 1;
  i = 0;
  while(flag){
    flag = 0;
    for(j=n-1; j>=i+1; j--){
      if(num[j] < num[j-1]){
	temp = num[j];
	num[j] = num[j-1];
	num[j-1] = temp;
	flag = 1;
	count++;
      }
    }
    i++;
  }

  for(j=0; j<n; j++){
    printf("%d", num[j]);
    if(j==n-1) break;
    printf(" ");
  }
  printf("\n");
  printf("%d\n", count);

  return 0;
}
