#include <stdio.h>
#include <stdlib.h>

int main()
 {
     int i;
     int key;
     int final = 0;
     int n,m;
     scanf("%d", &n);
     int A[10000];
     for (i = 0; i != n; i++)
    {
        scanf("%d", &A[i]);
 }


 scanf("%d", &m);
 while (m--) 
 {
      scanf("%d", &key);
      for (i = 0; i != n; i++) 
   {
       if (A[i] == key) 
        {
            final++;
            break;
   }
  }
 }

 printf("%d\n", final);
 return 0;
 


}
