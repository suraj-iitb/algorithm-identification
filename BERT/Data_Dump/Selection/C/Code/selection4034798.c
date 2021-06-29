#include <stdio.h>

int selectionSort(int *, int);

int main(){
  int n, number[100], a, count;

  scanf("%d",&n);
  for(a = 0; a < n; a++){
    scanf("%d",&number[a]);
  }

  count = selectionSort(number,n);
  for(a = 0; a < n-1; a++){
    printf("%d ",number[a]);
  }
  printf("%d\n",number[a]);
  printf("%d\n",count);

  return 0;
}

int selectionSort(int *p, int n){
  int a, b, count=0, min, temp;
  for(a = 0; a < n; a++){
    min = a;
    for(b = a; b < n; b++){
      if(*(p+b) < *(p+min)){
	min = b;
      }
    }
    if(*(p+a) == *(p+min)) continue;
    else{
      temp = *(p+a);
      *(p+a) = *(p+min);
      *(p+min) = temp;
      count++;
    }
  }
  return count;
}

