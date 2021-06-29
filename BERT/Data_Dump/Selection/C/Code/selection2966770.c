#include<stdio.h>
#include<stdlib.h>

int main(){
  int i,j,count=0,n,minj,x;
  int *A;

  scanf("%d",&n);

  if(n<1 || n>100)return 0;

  A = (int *)malloc(sizeof(int) * n);

for(i = 0;i < n;i++){
  scanf("%d",&A[i]);
    if(A[i]<0|| A[i]>100)return 0;
}

for(i = 0;i<n-1;i++){
     minj = i;
     for (j=i;j<n;j++){
       if(A[j] < A[minj]){
         minj = j;
       }
   }
   if(minj!=i){
   x=A[i];
  A[i] = A[minj];
  A[minj] = x;
  count++;
}
   }

   printf("%d",A[0]);
 for(i=1;i<n;i++){
   printf(" %d",A[i]);
 }
 printf("\n");
 printf("%d\n",count);

 return 0;

}

