#include <stdio.h>
#define N 100


int main(){

  int a[N], flag=1, cnt = 0, tmp = 0;
  int n, i;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
    //printf("bbb\n");                                                          
  }


  while(flag != 0){
    //printf("aaa\n");                                                          
    flag = 0;


  for(i = n - 1; i > 0; i--){
    if(a[i] < a[i-1]){
      tmp = a[i];
      a[i] = a[i-1];
      a[i-1] = tmp;
      cnt++;
      flag = 1;
    }
  }
  }

  for(i = 0; i < n; i++){
    if(i != n - 1) printf("%d ", a[i]);
    else printf("%d\n", a[i]);
  }
  printf("%d\n", cnt);

  return 0;

}

