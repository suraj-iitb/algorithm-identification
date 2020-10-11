#include<stdio.h>

 int main()
 {
   int i , j, b, v, k, A[200];
   scanf("%d",&b);
   for(i=0; i < b; i++){
    scanf("%d",&A[i]);
   }
   
   for(i=1; i<b; i++){
    v = A[i];
    j = i - 1;
    for(k=1; k<=b; k++){
      if (k > 1){
      printf(" ");
    }
      printf("%d", A[k-1]);
    }
   printf("\n");
    while(j >= 0 && A[j] > v){
     A[j+1] = A[j];
     j--;
    A[j+1] = v;
    }
   }
         for(k=1; k<=b; k++){
    if (k > 1){
    printf(" ");
    }
    printf("%d", A[k-1]);
  }
    printf("\n");
    
   return 0;
    }
