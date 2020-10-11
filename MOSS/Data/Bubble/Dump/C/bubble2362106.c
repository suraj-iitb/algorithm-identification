#include <stdio.h>

#define NMAX 100

int bubbleSort(int *A, int n);

int main(){
   int j, n, A[NMAX];
   int nswitch;
   scanf("%d",&n);
   for(j=0;j<n;j++) scanf("%d",A+j);
   nswitch=bubbleSort(A,n);
   printf("%d",A[0]);
   for(j=1;j<n;j++) printf(" %d",A[j]);
   printf("\n");
   printf("%d\n",nswitch);
   return 0;
}

int bubbleSort(int *A, int n){
   int nswitch, flag, j, tmp;
   nswitch=0;
   flag=1;
   while(flag){
      flag=0;
      for(j=n-1;j>0;j--){
         if(A[j]<A[j-1]){
            tmp=A[j]; A[j]=A[j-1]; A[j-1]=tmp;
            ++nswitch;
            flag=1;
         }
      }
   }
   return nswitch;
}
