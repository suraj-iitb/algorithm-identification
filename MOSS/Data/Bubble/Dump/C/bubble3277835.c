#include<stdio.h>
#include<stdlib.h>

#define N 100

int main() {
  int x,i,flag,temp,count = 0;
  int data[N];
  scanf("%d",&x);
  if(x < 0 || x > N) {
    exit(1);
  }
  
  for(i = 0; i < x; i++) {
    scanf("%d",&data[i]);
  }

  flag = 1;
  while(flag) {
    flag = 0;
    for(i = x - 1; i >= 1; i--) {
      if(data[i] < data[i - 1]) {
	temp = data[i - 1];
	data[i - 1] = data[i];
	data[i] = temp;
	count++;
	flag = 1;
      }
    }
  }

  for(i = 0; i < x; i++) {
    printf("%d",data[i]);
    if(i == x - 1) {
      break;
    }
    printf(" ");
  }
  printf("\n");
  printf("%d\n",count);

  return 0;
}
    

