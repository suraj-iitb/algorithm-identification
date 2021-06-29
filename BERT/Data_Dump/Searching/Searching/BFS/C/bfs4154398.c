//problem 11.b

#include <stdio.h>
#define M 10000
#define N 100
#define WHITE 1
#define GRAY 0
#define BLACK -2 
#define INF -1

void enq( int );
int deq( void );
void bfs( int );

int n, Q[M], adj[N+10][N+10], color[N+10], d[N+10], tail = 0, head = 0;//Q is queue, p is where queue is, and d is distance from 0 vertex to n vertex

int main(){
    int i, j, k;
    
    //initialize
    for(i = 0; i<=N; i++)
	for(j = 0; j<=N; j++)
	    adj[i][j] = -1;

    //input
    scanf("%d", &n);
    for(i = 1; i<=n; i++){//1-origin
	scanf("%d%d", &i, &k);
	for(j = 0; j<k; j++)//0-origin 
	    scanf("%d", &adj[i][j]);
    }
    //calculate
    bfs( 1 );
    //print
    for(i = 1; i<=n; i++) printf("%d %d\n",i, d[i]);
    return 0;
}

//------------------------------------------------------------------
void enq( int data ){

    if( tail == M )  tail = 0;
    Q[tail] = data;
    tail++;
    
    return ;
}

int deq( void ){
    int retval;

    if( head == M ){
	head = 0;
	retval = Q[head];
	head++;
    }
    else {
	head++;
	retval = Q[head-1];
    }

    return retval;
}

//--------------------------------------------------------------
void bfs( int start ){
    int i, j, u, v;

    //initialize
    for(i = 0; i<=n; i++){
	color[i] = WHITE;
	d[i] = INF;
    }
    color[start] = GRAY;
    d[start] = 0;
    enq( start );

    //calculate
    while(head != tail){
	u = deq();
	for(j = 0; adj[u][j] != -1; j++){
	    if( color[ adj[u][j] ] == WHITE ){
		color[ adj[u][j] ] = GRAY;
		d[ adj[u][j] ] = d[u] +1;
		enq( adj[u][j] );
	    }
	}
	color[u] = BLACK;
    }

    return ;
}

