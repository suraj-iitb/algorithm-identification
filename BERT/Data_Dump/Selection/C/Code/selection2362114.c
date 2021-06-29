#include <stdio.h>

#define NMAX 100

int selectionSort(int *A, int n);

int main(){
   int j, n, A[NMAX];
   int nswitch;
   scanf("%d",&n);
   for(j=0;j<n;j++) scanf("%d",A+j);
   nswitch=selectionSort(A,n);
   printf("%d",A[0]);
   for(j=1;j<n;j++) printf(" %d",A[j]);
   printf("\n");
   printf("%d\n",nswitch);
   return 0;
}

int selectionSort(int *A, int n){
   int nswitch, i, j, minj, tmp;
   nswitch=0;
   for(i=0;i<n;i++){
      minj=i;
      for(j=i;j<n;j++){
         if(A[j]<A[minj]) minj=j;
      }
      if(minj!=i){
         tmp=A[i]; A[i]=A[minj]; A[minj]=tmp;
         ++nswitch;
      }
   }
   return nswitch;
}
