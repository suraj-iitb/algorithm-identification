#include <stdio.h>

int BSearch( int A[], int N, int key ){
    int mid, left, right;
    left = 0;
    right = N;

    while (left<right){
        mid = (left+right)/2;
        if ( A[mid] == key ) return key;
        else if ( key < A[mid] ) right = mid;
        else left = mid + 1;
    }
   return 0;
}

int main()
{
   int n,q,i;
   int ans = 0;
   scanf("%d",&n);
   int s[n];
   for(i=0; i<n; i++){
     scanf("%d", &s[i]);
   }
   scanf("%d", &q);
   int t[q];
   for(i=0; i<q; i++){
     scanf("%d", &t[i]);
   }

   for(i=0; i<q; i++){
       int result = BSearch(s, n, t[i]);
       if(t[i]==result){
         ans = ans+1;
       }
   }
   printf("%d\n", ans);
   return 0;
}
