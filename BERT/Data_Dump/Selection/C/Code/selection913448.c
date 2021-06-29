#include <stdio.h>

#define MAX 100

int main(){
  int n,a[MAX],i,j,mini,tmp,ans = 0;

  scanf("%d" ,&n);
  for(i = 0 ; i < n ; i++){
    scanf("%d" ,&a[i]);
  }

  for(i = 0 ; i < n-1 ; i++){
    mini = i;
    for(j = i+1 ; j < n ; j++){
      if(a[mini] > a[j]){
	mini = j;
      }
    }
    if(mini != i){
      tmp = a[i];
      a[i] = a[mini];
      a[mini] = tmp;
      ans++;
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
