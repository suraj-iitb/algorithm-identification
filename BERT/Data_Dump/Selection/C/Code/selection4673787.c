#include <stdio.h>
#include<stdlib.h>


int main()
{
  int array[1000];
  int n;
  int i, j,mini, t;
  int count=0;
  
//number of array
  scanf("%d", &n);

//selectionsort
  for (i = 0; i < n; i++)
    scanf("%d", &array[i]);

  for (i = 0; i < (n - 1); i++) // finding minimum element (n-1) times
  {
    mini = i;

    for (j = i + 1; j < n; j++)
    {
      if (array[mini] > array[j])
        mini = j;
        
    }
    if (mini !=i)
    {
      t = array[i];
      array[i] = array[mini];
      array[mini] = t;
      count++;
    }
   
  }


 for (i = 0; i < n; i++) {
  if (i == n - 1)printf("%d\n", array[i]);
  else printf("%d ", array[i]);
 }

 printf("%d\n", count);
  return 0;
}
