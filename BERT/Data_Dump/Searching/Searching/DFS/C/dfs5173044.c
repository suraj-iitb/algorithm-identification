#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define N 100
void dfs();
void visit(int);
int next(int);

int nums[N][N], color[N], discovery[N], finishing[N], n, time;
int stack[N], s_top = 0;
int nt[N];
int main(){
    int i, j, k, l, m;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++) nums[i][j] = 0;
    }

    for(i = 0; i < n; i++){
        scanf("%d%d", &k, &l);
        k--;
        for(j = 0; j < l; j++){
            scanf("%d", &m);
            m--;
            nums[k][m] = 1;
        }
    }
    dfs();

    return 0;

}

void push(int u){
    if(s_top != N){
        stack[s_top + 1] = u;
        s_top++;
    }
}

int pop(){
    int x;
    if(s_top != 0){
        x = stack[s_top];
        s_top--;
    }
    return x;
}

void dfs(){
    int u, time;
    for(u = 0; u < n; u++){
        color[u] = WHITE;
    }
    time = 0;
    for(u = 0; u < n; u++){
        if (color[u] == WHITE) visit(u);
    }

    for(int i = 0; i < n; i++){
        printf("%d %d %d\n", i+1, discovery[i], finishing[i]);
    }
}

void visit(int r){
    int i, j, v;
    push(r);
    color[r] = GRAY;
    discovery[r] = ++time;
    while(s_top != 0){
        int u = stack[s_top];
        v = next(u);
        if(v != -1){
            if(color[v] == WHITE){
                push(v);
                color[v] = GRAY;
                discovery[v] = ++time;
            }
        }
        else{
            int p = pop();
            color[u] = BLACK;
            finishing[u] = ++time;
        }
    }

}

int next(int u){
    for(int v = nt[u]; v < n; v++){
        nt[u] = v + 1;
        if(nums[u][v])return v;
    }
    return -1;
}

