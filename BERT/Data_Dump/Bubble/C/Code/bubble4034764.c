#include <stdio.h>

int bubbleSort(int *, int);

int main(){
  int n, number[100], a, count;
  scanf("%d",&n);
  for(a = 0; a < n; a++){
    scanf("%d",&number[a]);
  }

  count = bubbleSort(number, n);
  for(a = 0; a < n-1; a++){
    printf("%d ",number[a]);
  }
  printf("%d\n",number[a]);
  printf("%d\n",count);
  return 0;
}

int bubbleSort(int *p, int n){
  int flag=1, a=0, b, temp, count=0;
  while(flag == 1){
    flag = 0;
    for(b = n-1; b > a; b--){
      if(*(p+b) < *(p+(b-1))){
	temp = *(p+b);
	*(p+b) = *(p+(b-1));
	*(p+(b-1)) = temp;
	flag = 1;
	count++;
      }
    }
    a++;
  }
  return count;
}

