#include<stdio.h>
#define N 100 
#define white 0
#define gray 1
#define black 2

int M[N][N],colour[N],d[N],Q[N+1],n;
int head=0,tail=0;

void enqueue(int x)
{
    Q[tail]=x;
    tail=(tail+1)%N;
}

int dequeue()
{
    int x;
    
    x=Q[head];
    head=(head+1)%N;
	
    return x;
}

void bfs()
{
    int u,s,v;
    for(u=0;u<n;u++){
        colour[u]=white;
        d[u]=-1;
    }

    colour[s]=gray;
    d[s]=0;
    enqueue(s);

    while(head!=tail){
        u=dequeue();
        for(v=0;v<n;v++){
            if(M[u][v]&&colour[v]==white){
                colour[v]=gray;
                d[v]=d[u]+1;
                enqueue(v);
            }
        }
        colour[u]=black;
    }

    for(u=0;u<n;u++){
        printf("%d %d\n",u+1,d[u]);
    }
}

int main()
{
    int i,j,u,v,k;
    
    scanf("%d",&n);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            M[i][j]=0;
        }
    }
    
    for(i=0;i<n;i++){
        scanf("%d",&u);
        scanf("%d",&k);
        for(j=0;j<k;j++){
            scanf("%d",&v);
	        M[u-1][v-1]=1;
        }
    }

    bfs();
  
    return 0;
}
