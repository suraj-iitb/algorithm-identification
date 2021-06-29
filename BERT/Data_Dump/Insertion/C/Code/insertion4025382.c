#include<stdio.h>
#define N 100

int main()
{
  int i,j,k,time=0,leng=0,key=0;
  int prop[N];

  scanf("%d",&time);

  for( i = 0 ; i < time ; i++ )
  {
    scanf("%d",&prop[i]);
  }


  for( i = 1 ; i < time+1 ; i++ )
  {

    for( k = 0 ; k < time ; k++ )
    {
      if( k == time-1 )printf("%d",prop[k]);
      else printf("%d ",prop[k]);
    }
    printf("\n");

    key = prop[i];

    j = i-1;
    while( j>= 0 && prop[j] > key )
    {
      prop[j+1] = prop[j];
      j--;
    }

    prop[j+1] = key;

  }

  return 0;
}

