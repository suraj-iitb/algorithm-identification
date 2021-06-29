#include <stdio.h>

#define N 100

void swap(int *, int *);

/*ここからがmain関数*/
int main()
{
  int i, j, n, A[N], count = 0, minj, k;


  scanf("%d", &n);

  for(i = 0; i < n; i++)
    scanf("%d", &A[i]);

  //printf("\n");

  /*
  if(n == 1){
    printf("%d\n%d\n", A[0], count);
    return 0;
  }

  */
 
  
  /*ここからがSelection Sort*/
  for(i = 0; i < n; i++){
    minj = i;
    for(j = i; j < n; j++){
      if(A[j] < A[minj])
	minj = j;

    }
    /*交換するswap関数*/
    if(A[i] > A[minj]){
    swap(&A[i], &A[minj]);
    count++;
    }
    
    /*確認のprintf*/
    /*
    for(k = 0; k < 6; k++){
      if(k != 0) 
	printf(" ");
      printf("%d", A[k]);
    }
    */
  
    //printf("\n");
  }


  /*ここからが出力*/
  for(i = 0; i < n; i++){
      if(i != 0) 
	printf(" ");
      printf("%d", A[i]);
    }
  
  printf("\n%d\n", count);

  return 0;
}


void swap(int *x, int *y)
{
  int tmp = 0;

  tmp = *x;
  *x = *y;
  *y = tmp;
}

