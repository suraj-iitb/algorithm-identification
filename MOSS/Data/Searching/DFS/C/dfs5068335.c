#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,M[N][N];
int color[N],d[N],f[N],t;

void dv(int u);



int main(void)
{
    int u,v,k,i,j;
    
    scanf("%d",&n);
    
    
    i=0;
    
    while(i<=n-1)
    {
        while(j<=n-1)
        {
            M[i][j]=0;
            j++;
        }
        j=0;
        i++;
        
        
    }
    i=0;
    j=0;
   
    
    while(i<n)
    {
        scanf("%d %d",&u,&k);
        u=u-1;
        
        while(j<k)
        {
            scanf("%d",&v);
            v=v-1;
            M[u][v]=1;
           j++;
        }
       i++;
       j=0;
    }
    
    
    u=0;
     while(u<n)
    {
        
        color[u]=WHITE;
        u++;
       
    }
    u=0;
   
    
    t=0;
    
    while(u<n)
    {
        if(color[u]==WHITE)
        {
            dv(u);
        }
        
        u++;
        
    }
    
    u=0;
    
   while(u<n)
    {
        printf("%d %d %d\n",u+1,d[u],f[u]);
        u++;
       
    }    
  
    return 0;
}


void dv(int u)
{
    int v;
    color[u]=GRAY;
    d[u]=++t;
    
    
    v=0;
    for(v=0;v<n;v++)
    {
        if(M[u][v]==0)
        {
            continue;
        }
        
        if(color[v]==WHITE)
        {
            dv(v);
        }
       
    }
        color[u]=BLACK;
        f[u]=++t;
        
    
}


