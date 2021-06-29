#include<stdio.h>
#include<math.h>

int count = 0;


void sort(int n, int a[]){
  int tmp;
  int min;
  int i ,j;
  for(i = 0; i < n; i++){
    min = i;
    int flag = 0;
    for(j = i; j < n; j++){
      if(a[j] < a[min]){
        min = j;
        flag = 1;
      }
    }
    tmp = a[i];
    a[i] = a[min];
    a[min] = tmp;
    if(flag == 1){
      count++;
    }
  }
}


int main(void){

  int a[100] = {};
  int n;
  int i;

  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }

  sort(n , a);

  for(i = 0; i < n-1; i++){
    printf("%d ", a[i]);
  }
  printf("%d\n", a[i]);
  printf("%d\n", count);

  return 0;
}

