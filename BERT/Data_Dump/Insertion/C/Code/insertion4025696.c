#include <stdio.h>

int main()
{
  int i,j,A[100],N,v,h;
  scanf("%d",&N);
  if( N >= 1 ){
    for( i = 0 ; i < N ; i++ ){
      scanf("%d",&A[i]);
    } 

    for( h = 0 ; h < N ; h++ ){
       if( h > 0 ) printf(" ");
       printf("%d",A[h]);
    }
     printf("\n"); 
    
    for( i = 1 ; i < N ; i++ ){
      v = A[i];
      j = i - 1;
      while( j >= 0 && A[j] > v ){
        A[j+1] = A[j];
        j--;
      }
      A[j+1] = v;
     for( h = 0 ; h < N ; h++ ){
       if( h > 0 ) printf(" ");
       printf("%d",A[h]);
    }
     printf("\n"); 
    }
    
    
  }
  return 0;
}

