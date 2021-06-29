#include <stdio.h>
#define  N 100
int main()
{
  int  A[N];
  int total;
  int  iS;
  int  iM;
  int  i,tmp,count=0;

  scanf("%d",&total);
  for(i=0;i<total;++i)
    scanf("%d",&A[i]);

  for(iS=0;iS<total-1;iS++){


        for( iM=iS,i=iS+1; i<total; i++ )
          {
            if ( A[i]<A[iM] ) iM=i;
          }

        if ( iS!=iM )
          {
            tmp=A[iM]; A[iM]=A[iS]; A[iS]=tmp;
            count++;
          }
  }
  for( i=0; i<total; i++ ){
    if(i){
      printf(" ");
    }
    printf("%d",A[i]);
  }
  printf("\n");
  printf("%d",count);
  printf("\n");
  return 0;
}

