#include<stdio.h>

int M[101][101];
int Q[101];
int n,HEAD=0,TAIL=0;
int VERT[101],d[101];

void Enqueue(int);
int Dequeue();

int Dequeue()
{
  int x;
  x=Q[HEAD];
  if(HEAD+1 == 100)HEAD=0;
  else HEAD=HEAD+1;
  return x;
}

void Enqueue(int a)
{
  Q[TAIL]=a;
  if(TAIL+1 == 100)TAIL=0;
  else TAIL=TAIL+1;
}

int main()
{
  int i,j,v,vv,m,u,k;

  scanf("%d",&n);
  for(i=0 ; i < n ; i++)
  {
    VERT[i]=0;
    for(j=0 ; j < n ; j++)
    {
      M[i][j]=0;
    }
  }
  for(i=0 ; i < n ; i++)
  {
    scanf("%d%d",&v,&m);
    for(j=0 ; j < m ; j++)
    {
      scanf("%d",&vv);
      M[v-1][vv-1]=1;
    }
  }

  for(j=0 ; j < n ; j++)
  {
    if(M[0][j] == 1)
    {
      VERT[j]=0;
    }
  }
  VERT[0]=1;
  d[0]=0;
  Enqueue(0);
  while(HEAD!=TAIL)
  {
    u=Dequeue();
    for(k=0 ; k < n ; k++)
    {
      if(M[u][k] == 1 && VERT[k] == 0)
      {
        VERT[k]=1;
        d[k]=d[u]+1;
        Enqueue(k);
      }
      VERT[u]=2;
    }
  }

  for(i=0 ; i < n ; i++)
  {
    if(VERT[i] == 2)printf("%d %d\n",i+1,d[i]);
    else printf("%d -1\n",i+1);
  }
  return 0;
}

