#include<stdio.h>

int main(){
  int n, i, check, tmp, t=0;
  scanf("%d",&n);
  int array[n];
  for(i = 0; i < n; i++) scanf("%d",&array[i]);

  check = 1;
  while(check == 1){
    check = 0;
    for(i = n-1; i >= 1; i--){
      if(array[i] < array[i-1]){
	tmp = array[i-1];
	array[i-1] = array[i];
	array[i] = tmp;

	t += 1;
	check = 1;
      }
    }
  }

  for(i = 0; i < n; i++) {
    if(i == n-1) printf("%d\n",array[i]);
    else printf("%d ",array[i]);
  }
  printf("%d\n", t);

  return 0;
}

  

