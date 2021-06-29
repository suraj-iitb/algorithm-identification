//
//  main.c
//  C
//
//  Created by s1262004 on 2019/07/19.
//  Copyright © 2019 s1262004. All rights reserved.
//

#include <stdio.h>
#include <limits.h>
#define qLength 100
int n;
int queue[qLength] = {-1}, qh, qt;
typedef struct node{
    int to[100];
    int edge;
    int color; // 0 -> WHITE, 1 -> GREY, 2 -> BLACK
    int d;
} node_t;

node_t vertex[100];

void bfs(int);
int isEmpty();
void enqueue(int);
int dequeue();

int main(int argc, const char * argv[]) {
    qh = qt = 0;
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int key, num;
        scanf("%d %d", &key, &num);
        vertex[key-1].d = -1;
        vertex[key-1].color = 0;
        vertex[key-1].edge = num;
        for (j = 0; j < num; j++) {
            int temp;
            scanf("%d", &temp);
            vertex[key-1].to[j] = temp - 1;
        }
    }
    
    bfs(0);
    
    for (i = 0; i < n; i++){
        printf("%d %d\n", i + 1, vertex[i].d);
    }
    
    
    return 0;
}

void bfs(int ix){
    vertex[ix].color = 1;
    vertex[ix].d = 0;
    enqueue(ix);
    
    while (!isEmpty()){
        int u = dequeue();
        for (int i = 0; i < vertex[u].edge; i++){
            int link = vertex[u].to[i];
            //printf("(%d, %d)\n", u, link);
            
            if (vertex[link].color == 0){
                vertex[link].color = 1;
                vertex[link].d = vertex[u].d + 1;
                enqueue(link);
            }
        }
        vertex[u].color = 2;
    }
}

int isEmpty(){
    if(qt == qh) return 1;
    return 0;
}

void enqueue(int x){
    queue[qt] = x;
    if (qt + 1 == qLength) qt = 0;
    else qt++;
}

int dequeue(){
    int x = queue[qh];
    if (qh + 1 == qLength) qh = 0;
    else qh++;
    return x;
}

