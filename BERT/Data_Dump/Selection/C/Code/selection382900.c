#include<stdio.h>
#define N 101

int main(){

  int i,j,n,key = 0,count = 0,array[N],mini;

  scanf("%d",&n);

  for(i = 0; i < n; i++){
    scanf("%d",&array[i]);
  }

  for(i = 0; i < n; i++){
    mini = i;
    for(j = i; j < n; j++){
      
      if(array[j] < array[mini]){
	mini = j;
      }
    }

    key = array[i];
    array[i] = array[mini];
    array[mini] = key;
    if(mini != i) count++; // 処理してないということ！
    
  }

  for(i = 0; i < n; i++){
    if(i < n-1) printf("%d ",array[i]);
    if(i == n-1) printf("%d\n",array[i]);
  }

  printf("%d\n",count);

  return 0;
}
