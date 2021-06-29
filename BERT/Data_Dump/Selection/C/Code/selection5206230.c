#include <stdio.h>

int main()
{
  int A[101], N, i, j, count, swap, temp;
  
  /*NO. OF ELEMENTS*/
  scanf("%d", &N);

  /*ELEMENTS*/
  for (i = 0; i < N; i++)
    scanf("%d", &A[i]);

  for(i = 0; i < N; i++)
    { 
      temp = i;
      for(j = i+1; j < N; j++)
        {if(A[j] < A[temp])
          temp=j;
        }
        if(A[i]>A[temp]){
          swap=A[i];
          A[i]=A[temp];
          A[temp]=swap;
          count=count+1;
          }
        }
      
      /*Sorted Array*/
      for(i = 0; i < N; i++){
        if(i) printf(" ");
        printf("%d",A[i]);
      } 

      /*COUNT OF SWAPPING*/
      printf("\n%d\n", count);
      return 0;
}
