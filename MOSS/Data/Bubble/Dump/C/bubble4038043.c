#include<stdio.h>
#include<stdlib.h>

#define N 100
#define A 100

int main(){

  int i, j, n, a[A], b = 0, temp1, temp2, count = 0;

  scanf("%d", &n);

  for(i = 0; i < n; i++)
    scanf("%d", &a[i]);

  b = 1;
  while(b == 1){
    b = 0;
    for(j = n - 1; j > 0; j--){
      if(a[j] < a[j - 1]){
	temp1 = a[j - 1];
	temp2 = a[j];
	a[j - 1] = temp2;
	a[j] = temp1;
	b = 1;
	count++;
      }
    }
  }

  for(i = 0; i < n; i++){
    
    if(i == n - 1){
      printf("%d", a[i]);
      continue;
    }
    
    printf("%d ", a[i]);
      
   
  }
  printf("\n%d\n", count);

  return 0;
}
      
	
    

