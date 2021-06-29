
#include <stdio.h>
#define N 100
 
int main()
{
  int array[N], n, i, j, position, swap,count;
 
   scanf("%d", &n);
 
   for ( i = 0 ; i < n ; i++ )
      scanf("%d", &array[i]);
 
   for ( i = 0 ; i <  n - 1  ; i++ )
   {
      position = i;
 
      for ( j = i + 1 ; j < n ; j++ )
      {
         if ( array[position] > array[j] )
            position = j;
      }
      if ( position != i )
      {
         swap = array[i];
         array[i] = array[position];
         array[position] = swap;
	 count ++;
      }
   }
 
  
   for ( i = 0 ; i < n - 1 ; i++ )
     {
      printf("%d ", array[i]);
     }
  
   printf("%d\n",array[i]);
   printf("%d\n",count);
   return 0;
}
