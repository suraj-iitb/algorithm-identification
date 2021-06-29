#include<stdio.h>
main()
{
  int A[101], i, j, length, key;

  scanf("%d",&length);
  for(i=1; i <= length; i++){
    scanf("%d", &A[i]); 
  }
  
  for(i=1; i <= length; i++){
    printf("%d", A[i]);
    if(i != length)printf(" ");
  }
  printf("\n");

 for(j = 2 ; j <= length; j++){
   key = A[j];
   /* insert A[j] into the sorted sequence A[1,...,j-1] */
   i = j - 1;
   
   while( i > 0 && A[i] > key ){
     A[i+1] = A[i];
     i = i - 1;
     A[i+1] = key;
   }
     for(i=1; i <= length; i++){
       printf("%d", A[i]);
       if(i != length)printf(" ");
			}
     printf("\n");
 }
 return 0;
}
