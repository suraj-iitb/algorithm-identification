#include<stdio.h>
#include<stdlib.h>

int bubbleSort(int *,int);

int main(){
  int n,count,i;
  int *a;

  count = 0;
  
  scanf("%d",&n);
  if(n < 1 || 100 < n)exit(0);

  a = malloc(n*sizeof(int));

  for(i = 0; i < n; i++){
    scanf("%d",a+i);
    if(*(a+i) < 0 || 100 < *(a+i))exit(1);
  }
  
  count = bubbleSort(a,n);
  
  for(i = 0; i < n; i++){
    if(i == 0){
      printf("%d",*(a+i));
      continue;
    }
    printf(" %d",*(a+i));
  }
  printf("\n");
  printf("%d\n",count);
  
  return 0;
}

int bubbleSort(int *a,int n){
  int count,i,flag,j,v;

  count = 0;
  flag = 1;
  
  while(flag){
    flag = 0;
    for(j = n - 1; j >= (i + 1); j--){
      if(*(a+j) < *(a+j-1)){
	v = *(a+j);
	*(a+j) = *(a+j-1);
	*(a+j-1) = v;
	count++;
	flag = 1;
      } 
    }
    i++;
  }
  
  return count;
}

