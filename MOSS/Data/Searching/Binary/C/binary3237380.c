#include <stdio.h>
 
int main(){

int n,i,q,key,mid,right,left,sum=0;
 
scanf("%d \n",&n);
 
int A[n];
 
for(i=0;i<n;i++){
scanf("%d ",&A[i]);
}

scanf("%d \n",&q);
 
for(i=0;i<q;i++){
scanf("%d ",&key);
left = 0;
right = n;
mid = (left+right)/2;
 
while(left<right){
   if(key == A[mid]){
   sum++;
   break;
   }
   else if(key<A[mid]){
    right = mid;
    mid = (left+right)/2;
    }
   else if(key>A[mid]){
    left = mid+1;
    mid = (left+right)/2;
    }
   }
}
 
printf("%d\n",sum);
 
return 0;
}
 



