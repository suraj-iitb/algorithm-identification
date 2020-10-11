#include <stdio.h>
#include <stdlib.h>
#define A 100

int bubbleSort(int *,int);

int main(){
  int a[A],n,i,count;

  scanf("%d",&n);
  
  if(n < 1 && n >100)exit(2);

  for(i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }
  count = bubbleSort(a,n);
  for(i = 0 ; i < n-1 ; i++){
    printf("%d ",a[i]);
  }
  printf("%d\n",a[i]);
  printf("%d\n",count);
  return 0;
}

int bubbleSort(int *a,int n){
  int i,j;
  int flag = 1;
  int num,count=0;
    
  while(flag == 1){
    flag = 0;
    for(j = n - 1; j >= 1 ; j--){
      if(a[j] < a[j-1]){
	num = a[j-1];
	a[j-1] = a[j];
	a[j] = num;
	flag = 1;
	count++;
      }
      i++;
    }
  }
  return count;
}

