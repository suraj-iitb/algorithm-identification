#include <stdio.h>
#include <stdlib.h>

int main()
 {
     int i;
     int key;
     int final = 0;
     int n,m;
     scanf("%d", &n);
     int A[100000];
     for (i = 0; i != n; i++)
    {
        scanf("%d", &A[i]);
 }


 scanf("%d", &m);
 int left, right, mid;
 while (m--) 
 {
     scanf("%d", &key);
     left = 0;
     right = n-1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (A[mid] == key) {
            final++;
            break;
   }
   else if (A[mid] > key) 
   {
       right = mid - 1;
   }
   else if (A[mid] < key)
   {
       left = mid + 1;
   }
  }
  
}
  
printf("%d\n", final);

 return 0;

}
