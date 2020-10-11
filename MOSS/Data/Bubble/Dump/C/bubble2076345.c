#include<stdio.h>

 int main()
 {
   int i , j, b, v, k, A[200], flag=1, count=0;
   scanf("%d",&b);
   for(i=0; i < b; i++){
    scanf("%d",&A[i]);
   }

    while(flag){
    flag = 0;
    for(j=b-1; j>=1; j--){
      if(A[j] < A[j-1]){
    k = A[j];
    A[j] = A[j-1];
    A[j-1] = k;
    count++;
    flag = 1;
      }
    }
  }
         for(k=1; k<=b; k++){
    if (k > 1){
    printf(" ");
    }
    printf("%d", A[k-1]);
  }
    printf("\n");
    
  printf("%d\n",count);
    
   return 0;
    }
