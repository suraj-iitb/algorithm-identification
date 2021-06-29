#include<stdio.h>

int binarySearch(int key,int n,int A[]){
  int L=0,R=n,mid;

  while(L<R){
    mid=(L+R)/2;
    if(A[mid]==key) return 1;
    else if(key<A[mid])R=mid;
    else L=mid+1;
  }
  return 0;
     }

   int main(){

     int i,j,n,count=0,N,A[1000000],key;


     scanf("%d",&n);
     for(i=0; i<n; i++){
       scanf("%d",&A[i]);
     }



     scanf("%d",&N);
     for(j=0; j<N; j++){
       scanf("%d",&key);
       if(binarySearch(key,n,A)!=0){
         count++;
       }
    }

 printf("%d\n",count);

     return 0;
   }





                                     
