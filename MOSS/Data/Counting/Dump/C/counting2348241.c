#include<stdio.h>
#include<stdlib.h>

#define VM 10000 
#define M 2000001

int main()
{
  unsigned short *P,*Q;

  int S[VM+1];
  int n,i,j;

  scanf("%d",&n);

  P = malloc(sizeof(short)*n+1);
  Q = malloc(sizeof(short)*n+1);

  for(i=0;i <=VM;i++)
    {
      S[i]=0;
    }

  for(i=0;i <n;i++)
    {
      scanf("%d",&P[i+1]);
      S[P[i+1]]++;
    }

  for(i=1;i<=VM;i++)S[i]=S[i]+S[i-1];
 
  for(j=1;j<=n;j++){
    Q[S[P[j]]] = P[j];
    S[P[j]]--;
  }
 
  
  for(i=1;i<=n;i++)
    {
      if(i>1)printf(" ");
      printf("%d",Q[i]);
    }
        printf("\n");
      return 0;
}
  
      
