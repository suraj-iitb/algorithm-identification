//
//  main.c
//  B
//
//  Created by s1262004 on 2019/07/19.
//  Copyright © 2019 s1262004. All rights reserved.
//

#include <stdio.h>
int n, timeUsed;
typedef struct node{
    int to[100];
    int edge;
    int color; // 0 -> WHITE, 1 -> GREY, 2 -> BLACK
    int dis, fin;
} node_t;

node_t vertex[100];

void dfs();
void visit(int);

int main(int argc, const char * argv[]) {
    int i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int key, num;
        scanf("%d %d", &key, &num);
        for (j = 0; j < num; j++) {
            int temp;
            scanf("%d", &temp);
            vertex[key-1].color = 0;
            vertex[key-1].edge = num;
            vertex[key-1].to[j] = temp - 1;
        }
    }
    
    dfs();
    
    for (i = 0; i < n; i++){
        printf("%d %d %d\n", i + 1, vertex[i].dis, vertex[i].fin);
    }
    
    
    return 0;
}

void dfs(){
    int i;
    timeUsed = 0;
    for (i = 0; i < n; i++){
        if (vertex[i].color == 0) visit(i);
    }
}

void visit(int ix){
    int i;
    vertex[ix].color = 1;
    vertex[ix].dis = ++timeUsed;
    
    for (i = 0; i < vertex[ix].edge; i++){
        int link = vertex[ix].to[i];
        //printf("(%d, %d)\n", ix, link);
        if (vertex[link].color == 0) visit(link);
    }
    
    vertex[ix].color = 2;
    vertex[ix].fin = ++timeUsed;
}

