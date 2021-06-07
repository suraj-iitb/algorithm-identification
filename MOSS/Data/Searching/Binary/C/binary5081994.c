#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define N 100000
#define Q 50000

    int main ()
   {
     int S[N],T[Q],n,q,i,j,cnt=0,left,right,key,mid;

     scanf("%d",&n);

     for(i=0;i<n;i++)
     {
      scanf("%d",&S[i]);
     }

      scanf("%d",&q);

     for(i=0;i<q;i++)
     {
      scanf("%d",&T[i]);
     }

    for ( i=0; i<q; i++ ) 
   {
        left = 0;
        right = n;
        key = T[i];
        
        while( left < right ) 
        {
            mid = (left + right) / 2;
            if ( key == S[mid] ) 
            {
                cnt++;
                break;
            } else if ( key < S[mid] ) {
                right = mid;
            } else if ( key > S[mid] ) {
                left = mid + 1;
            }
        }
    }
     printf("%d\n",cnt);
   }
