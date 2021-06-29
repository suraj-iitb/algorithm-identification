#include<stdio.h>

#define N 100

int main() {  
  int i,j,a,min,temp,count;
  int data[N];

  scanf("%d",&a);
  for(i = 0; i < a; i++) {
    scanf("%d",&data[i]);
  }

  for(i = 0; i < a; i++) {
    min = i;
    for(j = i; j < a; j++) {
      if(data[j] < data[min]) {
	min = j;
      }
    }
    temp = data[i];
    data[i] = data[min];
    data[min] = temp;
    if(i != min) {
      count++;
    }
  }

  for(i = 0; i < a; i++) {
    printf("%d",data[i]);
    if(i != a - 1) {
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}
      
      
	
	
  

  
  

