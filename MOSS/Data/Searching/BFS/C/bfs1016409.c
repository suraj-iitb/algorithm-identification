#include <stdio.h>
#define BLACK 0
#define WHITE 1
#define GRAY -1


int a[101][101];

int n;
int color[101];
int time=0;
int d[101];
int k;
int head=0,tail=0;
int queue[101];

void BFS (int);

void Enqueue(int u){
    if(tail == 101)tail=0;
    queue[tail] =u;
    tail++;
}

int Dequeue(void){
    if(head==101)head=0;
    return queue[head++];
    
}



int main(void){
    int t,u,i,j;

    
    
    scanf("%d",&n);
    
    
   for(i=1;j<=n;i++){
        for(j=1;j<=n;j++){
            a[i][j]=0;
        }
    }
    
    for(i=1;i<=n;i++){
        scanf("%d",&u);
        scanf("%d",&k);
        for(j=1;j<=k;j++){
            scanf("%d",&t);
            a[i][t] =1;
        }
        
    }
    

      BFS(1);
        
        for(i=1;i<=n;i++){
            if(d[i]==2147483647)d[i]=-1;
            printf("%d %d",i,d[i]);
            printf("\n");
        }
        
    return 0;
}
  
void BFS(int s){
        int u,v,i;
        int empty=0;
        
        
        for(u=1;u<=n;u++){
            color[u]=WHITE;
            d[u]=2147483647;
        }
        
        color[s]=GRAY;
        d[s]=0;

    
        Enqueue(s);
        empty++;
        
        while(empty!=0){
            u=Dequeue();
            empty--;
            for(v=1;v<=n;v++){
               //v=a[u][v];
                if(color[v] == WHITE && a[u][v]==1){
                    color[v]=GRAY;
                    d[v]=d[u]+1;
                    Enqueue(v);
                    empty++;
                }
            }
           //
            color[u]=BLACK;
        }
   
        
}

    
    
