#include <stdio.h>

#define N 100

int main(){

  int n; // array size
  int a[N]; //array
  int i,j; //loop
  int count = 0;
  
  // array size
  scanf("%d",&n);
  
  // array element
  for(i = 0 ; i < n ; i++){
    scanf("%d",&a[i]);
  }

  // bubble sort
  int emp;
  for( i = 0 ; i != n-1 ; i++){
    for( j = n-1 ; j != i; j--){
      if(a[j] < a[j-1]){
	emp = a[j];
	a[j] = a[j-1];
	a[j-1] = emp;
	count++;
      }
    }
  }

  // output
  for( i = 0 ; i < n ; i++){
    printf("%d",a[i]);
    if(i < n-1) printf(" ");
  }
  printf("\n%d\n",count);

  return 0;

}

