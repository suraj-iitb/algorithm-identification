#include<stdio.h>
#include<stdlib.h>


int bubblesort(int *,int);  /*戻り値は変換回数*/

int main(){
  int n, i, *A, k;


  scanf("%d",&n);

  A = malloc(sizeof(int) * n);


  for(i = 0 ; i < n ; i++){
    scanf("%d",&A[i]);
  }

   k = bubblesort(A,n);

   for(i = 0 ; i < n ; i++){
     if(i != 0 && i < n)printf(" ");
     printf("%d",A[i]);
   }

   printf("\n%d\n",k);


   return 0;
}

int bubblesort(int *a, int n){
  int i, b,k = 0, flag = 1;

  while(flag){
    flag = 0;

    for(i = n - 1; i >= 1 ; i--){
      if(a[i] < a[i-1]){
	k++;
	b = a[i];
	a[i] = a[i-1];
	a[i-1] = b;
	flag = 1;
      }
    }
  }
  return k;
}
      

  
  
  

  

