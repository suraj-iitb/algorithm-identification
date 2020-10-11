#include <stdio.h>
#define N 100
 
int main()
{
  int i, j, array[N], n, mini, swap,count = 0;
 
   scanf("%d", &n);
 
   for (i = 0;i < n;i ++)
      scanf("%d", &array[i]);
 
   for (i = 0;i < n - 1;i ++)
   {
      mini = i;
 
      for (j =  i + 1;j < n; j++)
      {
         if ( array[mini] > array[j] )
            mini = j;
      }
      if ( mini != i )
      {
         swap = array[i];
         array[i] = array[mini];
         array[mini] = swap;
	 count ++;
      }
   }
 
  
   for ( i = 0 ; i < n - 1; i++ )
     {
      printf("%d ", array[i]);
     }
  
   printf("%d\n",array[i]);
   printf("%d\n",count);
   return 0;
}
