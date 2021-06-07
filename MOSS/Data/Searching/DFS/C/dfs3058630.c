#include <stdio.h>
#include <stdlib.h>

#define GRAY 1
#define BLACK 2
#define WHITE 0

int time = 0;

int color[101], d[101], f[101];
int ppp[101][101];
int n = 0;

void dfs(){
    int i=0, h=0;
    for(h=0; h<n; h++){
        color[h]==WHITE;
    }
    time = 0;
    for(h=0; h<n; h++){
        if(color[h]==WHITE) visit(h);
    }
    for(i=0;i<n;i++){
        printf("%d %d %d\n",i+1,d[i],f[i]);
    }
}

void visit(int u){
    color[u] = GRAY;
    d[u] = ++time;
    int i = 0;
    for(i=0; i<n; i++){
        if(ppp[u][i]==1){
            if(color[i]==WHITE) visit(i);
        }
    }
    color[u] = BLACK;
    f[u] = ++time;
}

int main()
{
    int a1, a2, a3, a4, a5;
    scanf("%d", &n);
    for (a1=0; a1<n; a1++){
        scanf("%d %d", &a2, &a3);
        a2--;
        for(a4=0; a4<a3; a4++){
            scanf("%d", &a5);
            a5--;
            ppp[a2][a5] = 1;
        }
    }
    dfs();
    return 0;
}

