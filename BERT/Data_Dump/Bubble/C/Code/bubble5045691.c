#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *v,int n){
  int flag = 1;
  while(flag){
    flag = 0;
    for(int i =n-1; i > 0; i--){
      if(v[i] < v[i-1]){
	int t = v[i];
	v[i] = v[i-1];
	v[i-1] = t;
	flag = 1;
	v[n]+=1;
      }
    }
  }
}


int main(){
  int n;
  scanf("%d",&n);
  int *v;
  v = (int *)malloc(n * sizeof(int)+sizeof(int));
  for(int i = 0; i < n; i++){
    scanf("%d",&v[i]);
  }
  v[n] = 0;

  bubbleSort(v,n);
  for(int i = 0; i < n; i++){
    printf("%d",v[i]);
    if(i != n-1){
      printf(" ");
    }
  }
  printf("\n%d\n",v[n]);
}

