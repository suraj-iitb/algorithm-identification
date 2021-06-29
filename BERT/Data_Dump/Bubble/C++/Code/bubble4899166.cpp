#include <stdio.h>

int main()
{
 int S[100],N,i,j,temp,countS=0;
 scanf("%d",&N);
 for(i=0;i<N;i++)
  scanf("%d",&S[i]);
 for(i=0;i<N;i++)
  for(j=N-1;j>i;j--)
   if(S[j]<S[j-1])
   {
    temp=S[j];
    S[j]=S[j-1];
    S[j-1]=temp;
    countS++;
   }
 for(i=0;i<N-1;i++)
  printf("%d ",S[i]);  
 printf("%d\n%d\n",S[i],countS);
 return 0;
}
