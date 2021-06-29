#include <stdio.h>

int n, s[500000];
int a = 0;

void Merge(int left, int mid, int right)
{
   int n1 = mid - left;
   int n2 = right - mid;
   int L[n1+1], R[n2+1];
   int i, j, k;

   for ( i = 0; i < n1; i++ )
      L[i] = s[left + i];

   for ( i = 0; i < n2; i++ )
      R[i] = s[mid + i];
      L[n1] = 1000000000;
      R[n2] = 1000000000;

   i = 0;
   j = 0;

   for ( k = left; k < right; k++ ) {
      a++;

      if( L[i] <= R[j] )
         s[k] = L[i++];
      else
         s[k] = R[j++];

   }

}


void MergeSort(int left, int right)
{
   int mid;

   if( right -left <= 1 )
      return;

   mid = (left+right) / 2;
   MergeSort(left, mid);
   MergeSort(mid, right);
   Merge(left, mid, right);

}


int main()
{
   int i, left, right;

   scanf("%d", &n);

   for ( i = 0; i < n; i++ )
      scanf("%d", &s[i]);

   left = 0;
   right = n;
   MergeSort(left, right);

   for ( i = 0; i < n; i++ ){
      if( i > 0 )
         printf(" ");
         printf("%d", s[i]);
   }

   printf("\n");
   printf("%d\n", a);

   return 0;

}
