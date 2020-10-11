#include<stdio.h>
#define N 100

int bubbleSort(int*,int);

int main(void){
  int i,x,a[N],c;
  
  scanf("%d",&x);
  
  for(i = 0;i < x;i++){
    scanf("%d",&a[i]);
  }
  
  c = bubbleSort(a,x);
  
  for(i = 0;i < x;i++){ 
    if(i == x-1){
      printf("%d\n",a[i]);
      break;
    }
    printf("%d ",a[i]);
    
  }

  printf("%d\n",c);

  return 0; 
}

int bubbleSort(int *a,int x){
  int i = 0,j,h,count=0;
  
  for(i = 0;i < x;i++){
    for(j = x-1;j > i;j--){
      
      if(a[j] < a[j-1]){
	h = a[j];
	a[j] = a[j-1];
	a[j-1] = h;
	count++;
      }
    }
  }
  
  return count;
}
