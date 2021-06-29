#include <stdio.h>

#define MAX 100

int main(){
  int n,a[MAX],ans = 0,i,j,tmp;

  scanf("%d" ,&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d" ,a+i);
  }

  for(i = 0 ; i < n ; i++){
    for(j = n-1 ; j > i ; j--){
      if(a[j] < a[j-1]){
	tmp = a[j];
	a[j] = a[j-1];
	a[j-1] = tmp;
	ans++;
      }
    }
  }

  for(i = 0 ; i < n ; i++){
    if(i != n-1){
      printf("%d " ,a[i]);
    }else{
      printf("%d\n%d\n" ,a[i],ans);
    }
  }

  return 0;
}

