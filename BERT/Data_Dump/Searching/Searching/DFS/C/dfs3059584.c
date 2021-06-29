/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Ivan
 *
 * Created on July 27, 2018, 9:30 AM
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

/*
 * 
 */

int M[MAX][MAX], d[MAX], f[MAX], color[MAX];
int n, u, k, v, time;

void makeGraph(int size);
void dfs();
void visit(int r);

int main(int argc, char** argv) {
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) M[i][j] = 0;
    
    makeGraph(n);
    
    dfs();
    
    for (int ix = 0; ix < n; ++ix) printf("%d %d %d\n", ix+1, d[ix], f[ix]);
    
    return (EXIT_SUCCESS);
}

void makeGraph(int size)
{
    for (int i = 0; i < size; ++i)
    {
        scanf("%d %d", &u, &k);
        u--;
        for (int ix = 0; ix < k; ++ix)
        {
            scanf("%d", &v);
            v--;
            M[u][v] = 1;
        }
    }
}

void dfs()
{
    for (int i = 0; i < n; ++i) color[i] = WHITE;
    time = 0;
    for (int i = 0; i < n; ++i) if (color[i] == WHITE) visit(i);
}

void visit(int r)
{
    color[r] = GRAY;
    d[r] = ++time;
    for (int i = 0; i < n; ++i) if (M[r][i] == 1) if (color[i] == WHITE) visit(i);
    color[r] = BLACK;
    f[r] = ++time;
}
