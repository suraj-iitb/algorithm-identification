#include<stdio.h>
#define N 100
#define L 100000
#define NIL -1
int n;
int M[N][N];
int d[N];
int Q[L];
int head,tail;
void enqueue(int x)
{
    Q[tail]=x;
    tail=(tail+1)%L;
}
int dequeue()
{
    int x=Q[head];
    head=(head+1)%L;
    return x;
}

int main(void)
{
    int u,k,v;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        d[i]=NIL;
        for(int j=0;j<n;j++)
        {
            M[i][j]=0;
        }
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&u,&k);
        u--;
        for(int j=0;j<k;j++)
        {
            scanf("%d",&v);
            v--;
            M[u][v]=1;
        }
    }
   d[0] = 0;
    head = 0;
    tail = 0;
    enqueue(0);

  while(head != tail)
  {
      v = dequeue();
      for(int i=0;i<n;i++)
      {
          if(M[v][i] && d[i] == NIL)
          {
              d[i] = d[v]+1;
              enqueue(i);
              
          }
          
      }
  }


  for(int i=0;i<n;i++){
    printf("%d %d\n",i+1,d[i]);
  }
    return 0;
}

