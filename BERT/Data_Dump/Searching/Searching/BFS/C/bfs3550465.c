#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 100
#define INF  1e9

typedef struct tQueue_
{
    int queue[SIZE];
    int head;
    int tail;
}tQueue;

typedef struct tNode_
{
    int u;
    int k;
    int v[SIZE];
}tNode;

bool IsFull(tQueue *q){
    return (q->head == (q->tail + 1) % SIZE);
}

bool IsEmpty(tQueue *q){
    return (q->head == q->tail);
}

void Enqueue(tQueue *q, int value){
    if(IsFull(q)){
        return;
    }
    else{
        q->queue[q->tail] = value;
        q->tail = (q->tail + 1) % SIZE;
    }
}

int Dequeue(tQueue *q){
    if(IsEmpty(q)){
        return 0;
    }
    else{
        short data = q->queue[q->head];
        q->head = (q->head + 1) % SIZE;
        return data;
    }
}

void BFS(tQueue *q, tNode data[], int path[]){
    int node = Dequeue(q) - 1;

    for(int i = 0; i < data[node].k; i++){
        int nextNode = data[node].v[i] - 1;
        if(path[nextNode] < path[node] + 1){ continue; }
        path[nextNode] = path[node] + 1;
        Enqueue(q, nextNode + 1);
        BFS(q, data, path);
    }
}

int main(){
    tQueue q = {{0}, 0, 0};
    tNode data[SIZE];
    int n, path[SIZE];

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &data[i].u, &data[i].k);
        for(int j = 0; j < data[i].k; j++){
            scanf("%d", &data[i].v[j]);
        }
        path[i] = INF;
    }

    path[0] = 0;
    Enqueue(&q, 1);
    BFS(&q, data, path);

    for(int i = 0; i < n; i++){
        if(path[i] == INF){ path[i] = -1; }
        printf("%d %d\n", i + 1, path[i]);
    }

    return 0;
}
