#include <stdio.h>

void bubbleSort(int *,int);

int main(){
  int a[100],n,i;

  scanf("%d",&n);
  if(n < 1 || n > 100)return 0;
  
  for(i = 0; i < n; i++){
  scanf("%d",&a[i]);
  
  if(a[i] < 0 || a[i] > 100)return 0;
  }

  bubbleSort(a,n);

  return 0;
}

void bubbleSort(int a[],int n){
  int flag = 1,num = 0,b,j,i = 0;
  
  while(flag != 0){
    flag = 0;
    for(j = n-1; j > i; j--){
	 if (a[j-1] > a[j]){
	   b = a[j-1];
	   a[j-1] = a[j];
	   a[j] = b;
	   num++;
	   flag = 1;
	 }
       }
    i++;
  }
  
  
  for(j = 0; j < n; j++){
  printf("%d",a[j]);

  if(j != n-1)printf(" ");
  else printf("\n");
  }
  
  printf("%d\n",num);
  
}

