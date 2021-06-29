#include <stdio.h>
#define N 100

 int main(){
   int j,n,l,flag,count=0;

   scanf("%d",&n);

   int A[N];

   for(j=0 ; j<n ; j++){
     scanf("%d",&A[j]);
   }

flag = 1;

   while(flag){
     flag=0;
     for(j=0 ; j<n-1; j++){
       if(A[j]>A[j+1]){
      l=A[j];
      A[j]=A[j+1];
      A[j+1]=l;
      count++;
      flag=1;
    }
  }
}

for(j=0;j<n-1;j++){
    printf("%d ",A[j]);
}

  printf("%d",A[j]);
  printf("\n%d\n",count);
    return 0;
}

