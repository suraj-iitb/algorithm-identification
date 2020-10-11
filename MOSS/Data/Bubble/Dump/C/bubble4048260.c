#include <stdio.h>

#define N 100

int bubbleSort(int a[],int n);

int main() {
  
  int n,a[N],k,i;

  scanf("%d", &n);
  
  for(i = 0; i < n; i++){
    
    scanf("%d",a+i);

  }

  k = bubbleSort(a, n);
  
  for(i = 0; i < n; i++){

    if(i>0){
      printf(" ");
    }
    
    printf("%d", a[i]);

  }
  
  printf("\n");
  
  printf("%d\n",k);

  return 0;
}

int bubbleSort(int a[], int n) {
  int j,b,k=0,flag=1;

  while(flag) {
    flag = 0;
    for(j = n-1; j > 0;j--) {
      if(a[j] < a[j-1]) {
        b = a[j];
        a[j] = a[j-1];
        a[j-1] = b;
        flag = 1;
        k++;
      }
    }
  }
  return k;
}


