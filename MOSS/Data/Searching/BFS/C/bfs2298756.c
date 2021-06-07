#include <stdio.h>
#include <memory.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2 
int queue[100],len[100],color[100],M[100][100],n;

void bfs(void){ 
    int sign,top,end,i;
    memset(len,-1,sizeof(len));
    len[0]=0;
    for(top=0,end=1;end != top;){
        sign=queue[top];
        top++;
        for(i=0;i<n;i++){
            if(M[sign][i]!=0 && color[i]==WHITE){
                queue[end++]=i;
                len[i]=len[sign]+1;
                color[i]=GRAY;
            }
        }
        color[sign]=BLACK;
    }
    for(i=0;i<n;i++)
        printf("%d %d\n",i+1,len[i]);
}
int main(void){
    int u,k,v,i,o;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d %d",&u,&k);
        u--;
        for(o=0;o<k;o++){
            scanf("%d",&v);
            v--;
            M[u][v]=1;
        }
    }
    color[0]=BLACK;
    bfs();
    return 0;
}
