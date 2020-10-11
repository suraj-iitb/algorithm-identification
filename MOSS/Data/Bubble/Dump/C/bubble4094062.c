#include <stdio.h>
#define  N  100
int  main( )
{
  int total,i,j,tmp,count=0;
  int  A[N];
  scanf("%d",&total);
    for( i=0; i<total; i++ )
       scanf("%d",&A[i]);
    for(j=total;j>1;j--){
    for( i=0; i<total-1; i++ ){
            if ( A[i]>A[i+1] )
              {
                tmp=A[i];
                A[i]=A[i+1];
                A[i+1]=tmp;
                count++;
              }
          }
    }
    for( i=0; i<total; i++ )
      {
        if(i){
          printf(" ");
        }
        printf("%d",A[i]);
      }
    printf("\n");
    printf("%d",count);
    printf("\n");
    return  0;
}


