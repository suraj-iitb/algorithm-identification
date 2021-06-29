#include <stdio.h> // selection sort

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

  //selectionSort
  int minj;
  for(i = 0 ; i < n-1 ; i++){
    minj = i;
    for(j = i ; j < n ; j++){
      if(a[j] < a[minj]){
	minj = j;
      }
    }
    int memo;
    memo = a[i];
    a[i] = a[minj];
    a[minj] = memo;
    if(i != minj) count++;      
  }


// output
  for( i = 0 ; i < n ; i++){
    if(i > 0) printf(" ");
    printf("%d",a[i]);
  }
  printf("\n");
  printf("%d\n",count);

  return 0;

}

