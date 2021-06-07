#include <stdio.h>

 int main(){
     int n,s,x,i,j,count;
     int a[10000];
     int q[10000];
     x = 0;
     count = 0;
     scanf("%d",&n);
     for (i = 0; i < n; i++)
         scanf("%d", &a[i]);
     scanf("%d",&s);
     for (i = 0; i < s; i++)
         scanf("%d", &q[i]);
     for(j=0; j<s; j++) {
         for (i=0; i<n; i++){
             if (a[i] == q[j]){
                 count++;
                 break;
             }
         }
     }
     printf("%d\n",count);
     return 0;
 }
