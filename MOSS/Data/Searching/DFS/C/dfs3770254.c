#include <stdio.h>
#define MAX_LENGTH 101
#define WHITE 0
#define GRAY 1
#define BLACK 2
int tm;
int discovery[MAX_LENGTH];
int finish[MAX_LENGTH];
int color[MAX_LENGTH];
int adj[MAX_LENGTH][MAX_LENGTH];
void initial(int numV, int adj[MAX_LENGTH][MAX_LENGTH])
{
    for(int i = 0;i<numV;i++)
    {
        for(int j = 0;j<numV;j++)
        {
            adj[i][j]=0;
        }
    }
}
void printTime(int numV, int discovery[], int finish[])
{
    for(int i = 0;i<numV;i++){printf("%d %d %d\n", i+1, discovery[i], finish[i]);}
}
void visit(int i, int numV)
{
    color[i] = GRAY;
    discovery[i] = ++tm;
    for(int j=0;j<numV;j++)
    {
        if(adj[i][j]==0)continue;
        if(color[j]==WHITE){visit(j, numV);}
    }
    color[i] = BLACK;
    finish[i]=++tm;
}
void DFS(int numV)
{
    for(int i = 0;i<numV;i++){color[i]=WHITE;}
    tm = 0;
    for(int i = 0;i<numV;i++)
    {
        if(color[i]==WHITE){visit(i, numV);}
    }
}
int main(){
    int numV, numA, temp, node;
    scanf("%d", &numV);
    initial(numV, adj);
    for(int i = 0;i<numV;i++)
    {
        scanf("%d", &node);
        scanf("%d", &numA);
        for(int j = 0;j<numA;j++)
        {
            scanf("%d", &temp);
            adj[i][temp-1] = 1;
        }
    }
    DFS(numV);
    printTime(numV, discovery, finish);
    return 0;
}


