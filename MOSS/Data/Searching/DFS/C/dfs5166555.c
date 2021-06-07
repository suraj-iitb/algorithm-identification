#include <stdio.h>

#define N 101
#define WHITE 0
#define GYAY 1
#define BLACK 2

int sum, Mat[N][N], color[N], d[N], f[N], nt[N], time, top = 0, Stack[N];

void push(int x){
    top++;
    Stack[top] = x;
}

int pop(){
    top--;
    return Stack[top+1]; 
}

int printTop(){
    return Stack[top];
}

int empty(){
    if(top == 0)return 1;

    return 0;
}

int next(int vertex){
    int i;
    for(i = nt[vertex]; i < sum; i++){
        nt[vertex] = i + 1;
        if(Mat[vertex][i]) return i;
    }

    return -1;
}

void dfsInit(){
    for(int i = 0; i < sum; i++){
        color[i] = WHITE;
        nt[i] = 0;
    }
    time = 0;
}

void dfsSearch(int r){
    int i;

    for(i = 0; i < sum; i++)nt[i] = 0;

    push(r);
    color[r] = GYAY;
    time++;
    d[r] = time;

    while (empty() != 1){
        int u = printTop();
        int v = next(u);

        if(v != -1){
            if(color[v] == WHITE){
                color[v] = GYAY;
                time++;
                d[v] = time;
                push(v);
            }
        } else {
            pop();
            color[u] = BLACK;
            time++;
            f[u] = time;
        }
    }   
}

void dfs(){
    dfsInit();

    for(int u = 0; u < sum; u++){
        if(color[u] == WHITE) dfsSearch(u);
    }
}

int main(){
    int i, j, vertex, num, temp;

    scanf("%d", &sum);

    for(i = 0; i < sum;i++){
        for(j = 0;j < sum; j++){
            Mat[i][j] = 0;
        }
    }

    for(i = 0; i < sum; i++){
        scanf("%d%d", &vertex, &num);
        vertex--;

        for(j = 0; j < num; j++){
            scanf("%d", &temp);
            Mat[vertex][temp-1] = 1;
        }
    }

    dfs();

    for(i = 0; i < sum; i++){
        printf("%d %d %d\n", i+1, d[i], f[i]);
    }
    return 0;
}
