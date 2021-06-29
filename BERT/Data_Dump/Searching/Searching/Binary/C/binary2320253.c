#include<stdio.h>
 
#define N 100000
 
 
 
main(){
 
int n, q;
int S[N], T;
int i, j;
int k=0, count=0;
int left, right, mid;
 
 
scanf("%d",&n);
 
for(i = 0; i < n; i++){
scanf("%d",&S[i]);
}
 
scanf("%d",&q);
 
for(j = 0; j < q; j++){
scanf("%d",&T);
 left = 0;
 right = n;
 
while(left < right){
mid = (left+right)/2;
 
 if(T==S[mid]){
   count++;
   break;
 }
 
 if(T > S[mid]){
   left = mid +1;
 }
 
 else if(T < S[mid]){
    right = mid;
 }
}
 }
printf("%d\n",count);
return 0;
}
