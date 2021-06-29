#include <stdio.h>
 
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define INF -1
  
int matrix[MAX+1][MAX+1];
int n;
int Q[MAX+1];
int d[MAX+1];
int color[MAX+1];
int head = 0, tail = 0;
 
void enq(int x){
    Q[tail] = x;
    tail++;
  
    if( tail == MAX+1 ){
        tail = 0;
    }
}
  
int deq(){
    int n;
    n = Q[head];
    head++;
  
    if( head == MAX+1 ){
        head = 0;
    }
  
    return n;
}
  
void bfs(int s){
    int i,v,u;
  
    for( i = 0 ; i <= n ; i++ ){
        color[i] = WHITE;
        d[i] = INF;
    }
  
    color[s] = GRAY;
    d[s] = 0;
    enq(s);
  
    while( tail != head ){
  
        u = deq();
  
        for( i = 1 ; i <= n ; i++ ){
  
            if( color[i] == WHITE && matrix[u][i] == 1 ){
  
                color[i] = GRAY;
                d[i] = d[u]+1;
  
                enq(i);
            }
        }
        color[u] = BLACK;
    }
}
  
int main(){
    int i,j;
    int row,col;
    int num;
  
    scanf("%d",&n);
  
  
    for( i = 0 ; i <= n ; i++ ){
        for( j = 0 ; j <= n ; j++ ){
            matrix[i][j] = WHITE;
        }
    }
  
    for( i = 1 ; i <= n ; i++ ){
  
        scanf("%d",&row);
        scanf("%d",&col);
  
        for( j = 0 ; j < col ; j++ ){
            scanf("%d",&num);
            matrix[row][num] = 1;
        }
  
    }
  
    bfs(1);
  
    for( i = 1 ; i <= n ; i++ ){
        printf("%d %d\n",i,d[i]);
    }
  
  
    return 0;
}
