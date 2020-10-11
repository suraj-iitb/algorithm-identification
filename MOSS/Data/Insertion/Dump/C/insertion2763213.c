#include<stdio.h>
#define MAX 100


void insertionSort(int A[],int n){
 int i,j;
 int x;
 
 for(i=0;i<n;i++){

   x=A[i];
   j=i-1;
   while(j>=0 && x<A[j]){
      A[j+1]=A[j];
      j--;
   }
   A[j+1]=x;
   for(j=0;j<n-1;j++)printf("%d ",A[j]);
   printf("%d\n",A[n-1]);

 }


return;
}

int main(){
 int n,i;
 int A[MAX];

 scanf("%d",&n);
 for(i=0;i<n;i++)scanf("%d",&A[i]);

 insertionSort(A,n);

return 0;
}
