#include <stdio.h>
#define M 102
typedef struct GG{
    int name;
    int dis;
    int fin;
    int next[M];
    char color;
}G;

G u[M];
int n,time;

void search(int x){
    int y=1;
    u[x].dis = time;
    time++;
    u[x].color = 'r';
    for(y=1;y<=n;y++){
        if(u[u[x].next[y]].color == 'w'){
            search(u[x].next[y]);
        }
    }
    u[x].fin = time;
    time++;
    u[x].color = 'b';
}

int main(void){
    int i,j,k;
    time =1;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        u[i].dis = 0;
        u[i].fin = 0;
        u[i].color = 'w';
    }
    u[n+1].color='b';
    for(i=1;i<=n;i++){
        scanf("%d%d",&u[i].name,&k);
        for(j=1;j<=k;j++){
            scanf("%d",&u[i].next[j]);
        }
        u[i].next[j]= -1;
    }
//    for(i=1;i<=n;i++){
//        printf("%d ",u[i].name);
//        k=1;
//        while(u[i].next[k] != -1){
//            printf("%d ",u[i].next[k]);
//            k++;
//        }
//        printf("\n");
//    }
    for(int v=1;v<=n;v++){
        if(u[v].color == 'w'){
            search(v);
        }
    }

    for(i=1;i<=n;i++){
        printf("%d %d %d\n",u[i].name,u[i].dis,u[i].fin);
    }
    
    return 0;
}

