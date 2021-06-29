#include <stdio.h>
#include <stdlib.h>

void print_A(int n, int *A);

int main(){
   int i, j, n, v, *A;
   scanf("%d",&n);
   A=malloc(n*sizeof(int));
   for(i=0;i<n;i++) scanf("%d",A+i);
   for(i=1;i<n;i++){
      print_A(n,A);
      v=A[i];
      for(j=i-1;j>=0&&A[j]>v;j--) A[j+1]=A[j];
      A[j+1]=v;
   }
   print_A(n,A);
   return 0;
}

void print_A(int n, int *A){
   int j;
   for(j=0;j<n;j++){
      if(j!=0) printf(" ");
      printf("%d",A[j]);
   }
   printf("\n");
}
