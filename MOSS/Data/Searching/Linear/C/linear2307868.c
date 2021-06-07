#include<stdio.h>
 int linersearch(int*,int,int);
 #define N 10000
 int main() {
   int i,n,m,key,A[N+1],c=0;
   scanf("%d",&n);
   for (i = 0; i < n; i++){
     scanf("%d",&A[i]);
   }
   scanf("%d",&m);
   for (i = 0; i < m; i++) {
     scanf("%d",&key);
     if(linersearch(A,key,n)){
       c++;
     }
   }
   printf("%d\n",c);
   return 0;
 }
 int linersearch(int *a,int k,int x){
   int j=0;
   a[x]=k;
   while(a[j] != k){
     j++;
   }
   return j != x;
 }
