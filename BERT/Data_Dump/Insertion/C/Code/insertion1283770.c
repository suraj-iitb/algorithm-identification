#include<stdio.h>


main()
{
  int A[100],N;
  int i,k,key,j;

scanf("%d",&N);

for (k=0;k<N;k++)scanf("%d",&A[k]);

for (k=0;k<N;k++){
printf("%d",A[k]);
if(k!=N-1){printf(" ");}
}
printf("\n");

for (i=1;i<=N-1;i++){   

 
    key = A[i];
    /* insert A[i] into the sorted sequence A[0,...,j-1] */
    j = i-1;

      while(j>= 0 && A[j]>key){
        A[j+1] = A[j];
        j--;
       }
    A[j+1] = key;

for (k=0;k<N;k++){
         printf("%d",A[k]);
if(k!=N-1)printf(" ");}   

printf("\n");
  }

	  return 0;
}
