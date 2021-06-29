#include <stdio.h>
#include <stdbool.h>
#define SIZE 101

int cnt = 1;

typedef struct tStack_
{
    int data[SIZE];
    int top;
}tStack;

typedef struct tTimeStamp_
{
    int start;
    int end;
}tTimeStamp;

typedef struct tNode_
{
    int u;
    int k;
    int v[SIZE];
}tNode;

bool IsFull(tStack *s){
    return (s->top >= SIZE - 1);
}

bool IsEmpty(tStack *s){
    return (s->top == 0);
}

void Push(tStack *s, int value){
    if(IsFull(s)){
        return;
    }
    else{
        s->top++;
        s->data[s->top] = value;
    }
}

int Pop(tStack *s){
    if(IsEmpty(s)){
        return -1;
    }
    else{
        s->top--;
        return s->data[s->top + 1];
    }
}

void DFS(tStack *s, tTimeStamp ts[], tNode data[]){
    int node = Pop(s) - 1;
    int ref = 1;

    if(ts[node].start > 0 || ts[node].end > 0){ return; }

    ts[node].start = cnt++;
    while(1){
        if(ref > data[node].k){ break; }
        Push(s, data[node].v[ref - 1]);
        DFS(s, ts, data);
        ref++;
    }
    ts[node].end = cnt++;
}

int main(){
    tStack s = {{0}, 0};
    tTimeStamp ts[SIZE] = {{0, 0}};
    tNode data[SIZE];
    bool endFlag = true;
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &data[i].u, &data[i].k);
        for(int j = 0; j < data[i].k; j++){
            scanf("%d", &data[i].v[j]);
        }
    }

    Push(&s, 1);
    while(endFlag){
        DFS(&s, ts, data);
        for(int i = 0; i < n; i++){
            if(ts[i].start == 0 || ts[i].end == 0){
                Push(&s, i + 1);
                break;
            }
            else if(i == n - 1){
                endFlag = false;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d %d %d\n", i + 1, ts[i].start, ts[i].end);
    }

    return 0;
}
