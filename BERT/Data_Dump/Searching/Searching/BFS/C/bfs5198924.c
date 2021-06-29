#include<stdio.h>
#define INFTY (1<<21)
#define MAX 101

int head,tail,n,M[MAX][MAX],q[MAX],d[MAX];

int empty(void);
void init(void);
void enqueue(int);
int dequeue(void);
void dfs(int);

int main()
{
    int i,j,k,u,v;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        for(i=0;i<n;i++) M[i][j]=0;
    }
    
    for(i=0;i<n;i++){
        
        scanf("%d%d",&u,&k);
        
        u--;
        
        for(j=0;j<k;j++){
            
            scanf("%d",&v);
            
            v--;
            
            M[u][v]=1;
        }
    }
    
    bfs(0);
    
    return 0;
}
int empty()
{
  return head==tail;
  
}
void init()
{
  head=tail=1;
  
}

void enqueue(int a)
{
  q[tail++]=a;
  
}

int dequeue()
{
  int a;
  
  a=q[head++];
  return a;
  
}
void bfs(int s)
{
  int i, u, v;
  
  init();
  enqueue(s);
  
  for(i=0;i<n;i++) d[i]=INFTY;
  d[s]=0;
  
  while(!empty()){
      
    u=dequeue();
    
    for (v=0;v<n;v++){
        
      if(M[u][v]==0) continue;
      if(d[v]!=INFTY) continue;
      
      d[v]=d[u]+1;
      
      enqueue(v);
    }
  }
  
  for (i=0;i<n;i++){
      
    printf("%d %d\n", i+1,((d[i]==INFTY)?(-1):d[i]));
    
  }
}


