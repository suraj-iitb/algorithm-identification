#include<stdio.h>

int main() {
   int n;
   int A[10000],B[10000],a,b;
   int s;
   int i,j,k=0;

   scanf("%d\n",&n);
   for (i=0; i<n; i++) {
      scanf("%d",&a);
      A[i]=a;
   }
   scanf("%d\n",&s);
   for (i=0; i<s; i++) {
      scanf("%d",&b);
      B[i]=b;
  }

   for (i=0; i<n; i++)
      for (j=0; j<s; j++)
         if (A[i]==B[j]) {
            k++;
            A[i]=-1;
            B[j]=-2;
        }
   printf("%d\n",k);

   return 0;

}
