#include<stdio.h>

#define N 100

void selectionSort(int*Sort,int n){

  int i,j,min,tmp,cnt=0;

  for(i = 0;i < n;i++){
    min = i;
    for(j = i;j < n;j++){

      if(Sort[j] < Sort[min]){
	min = j;

      }
    }   
    if(Sort[i] != Sort[min]){ 
      tmp = Sort[i];
      Sort[i] = Sort[min];
      Sort[min] = tmp;
      cnt++;
    }
    
  }

  for(i = 0;i < n-1;i++)
    printf("%d ",Sort[i]);
  printf("%d\n",Sort[n-1]);
  printf("%d\n",cnt);
}

int main(){

  int n,i;
  int Sort[N];

  scanf("%d",&n);

  for(i = 0;i < n; i++)
    scanf("%d",&Sort[i]);

  selectionSort(Sort,n);

  return 0;
}
