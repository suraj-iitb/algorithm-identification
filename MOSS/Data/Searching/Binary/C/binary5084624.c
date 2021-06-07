#include <stdio.h>

int Y[1000000],num;

int binarySearch(int bn)
{
  int N = 0,R = num,M;

  while(N< R){
    M = (N + R) /2;
    if(bn == Y[M]) 
    {
      return 1;
    }
    if(bn > Y[M]) 
    {
      N = M +1;
    }
    else if(bn < Y[M]) 
    {
      R = M;
    }
  }
    return 0;
  }

    int main()
    {
      int i,num2,bn,S=0;

      scanf("%d",&num);
      for(i=0;i<num;i++)
      {
 scanf("%d",&Y[i]);
      }

      scanf("%d",&num2);
      for(i=0;i<num2;i++)
      {
 scanf("%d",&bn);
 if(binarySearch(bn))
 {
   S++;
 }
      }
 printf("%d\n",S);

 return 0;
      }
