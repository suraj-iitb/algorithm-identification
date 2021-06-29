#include<stdio.h>
#define N 100
#define MAX 1000

int main() {
  int n,i,j,k,key;
  int data[N];
  scanf("%d",&n);
  for(i = 0; i < n; i++) {
    scanf("%d",&data[i]);
  }

  for(i = 1; i < n; i++) {
    
    for(k = 0; k < n; k++) {
      printf("%d",data[k]);
      if(k != n - 1) {
	printf(" ");
      }
    }
    printf("\n");
    
    key = data[i];
    j = i - 1;
    while(j >= 0 && data[j] > key) {
      data[j + 1] = data[j];
      j--;
      data[j + 1] = key;
    }
  }

  for(i = 0; i < n; i++) {
    printf("%d",data[i]);
    if(i != n - 1) {
      printf(" ");
    }
  }
  printf("\n");

   return 0;
}
  
    
  

