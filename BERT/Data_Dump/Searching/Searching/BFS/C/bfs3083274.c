#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define M 110
#define NIL -1
 
int n;
int G[M][M];
int d[M];
int Q[M];
int c[M];
int t = 0;

void enQ(int);
int deQ(void);
void bfs(int);

int main(){    
    int i = 10;
    int j = 3;
    int k;
    int u;
    int v;
     
    scanf("%d",&n);   
    for(j=1;j<=n;j++){
        for(i=1;i<=n;i++){
            G[j][i] = 0;
        }
    }
    for(j=1;j<=n;j++){
        scanf("%d %d",&u,&k);
        for(i=1;i<=k;i++){
            scanf("%d",&v);
            G[u][v]=1;
        }
    }
    bfs(1);
     
    for(i=1;i<=n;i++){
        if(d[i] == 1000) d[i] = NIL;
        printf("%d %d\n",i,d[i]);
    }
     
    return 0;
     
}

 
void enQ(int a){
  static int x;
  if(x == 110) x = 0;
    Q[x] = a;
    x++;
}
 
int deQ(void){
  static int h;
    if(h == 110) h = 0;
    return Q[h++];
}
 
void bfs(int x){
  int i;
  int j;
  int e = 0;
  
    for(j=1;j<=n;j++){
        c[j] = 0;
        d[j] = 1000;
    }   
    c[x] = NIL;
    d[x] = 0;
    enQ(x);
    e++;
     
    while(e != 0){
        j = deQ();
        e--;
        for(i=1;i<=n;i++){
            if(c[i] == 0 && G[j][i] == 1){
                c[i] = NIL;
                d[i] = d[j] + 1;
                enQ(i);
                e++;
            }
        }
        c[j] = 1;
    }
}


