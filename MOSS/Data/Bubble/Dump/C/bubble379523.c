#include <stdio.h>
int main(){
  int i, j, n, num[101], cnt=0, tmp;
  
  scanf("%d", &n);
  for(i = 0 ; i < n ; i++){
    scanf("%d", &num[i]);
  }

  for(i = 0 ; i < n ; i++){
    for(j = n-1 ; j > i ; j--){
      if(num[j] < num[j-1]){
	cnt++;
	tmp = num[j];
	num[j] = num[j-1];
	num[j-1] = tmp;
      }
    }
  }

  for(i = 0 ; i < n ; i++){
    printf("%d%c", num[i], (i == n-1)? '\n':' ');
  }
  printf("%d\n", cnt);

  return 0;
}
