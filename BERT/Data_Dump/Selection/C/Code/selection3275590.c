#include<stdio.h>

int main(){
  int n, i, j, minj, tmp, cnt = 0, flag;
  scanf("%d", &n);

  int array[n];
  for(i = 0; i < n; i++) scanf("%d", &array[i]);

  for(i = 0; i < n; i++){
    minj = i;
    flag = 0;
    for(j = i; j < n; j++){
      if(array[j] < array[minj]) {
	minj = j;
	flag = 1;
      }
    }
    if(flag == 1){
      tmp = array[i];
      array[i] = array[minj];
      array[minj] = tmp;
    
      cnt++;
    }
  }

  for(i = 0; i < n; i++){
    if(i == n-1) printf("%d\n",array[i]);
    else printf("%d ",array[i]);
  }
  printf("%d\n",cnt);

  return 0;
}

