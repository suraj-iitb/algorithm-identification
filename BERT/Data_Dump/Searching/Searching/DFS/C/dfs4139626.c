#include <stdio.h>
#define WHITE 1
#define GRAY 0
#define BLACK -1

void dfs( void );//this is recursive function
void visit( int );

int adj[100+1][100+1];//this is a adjacency list. 1-origin.
int d[100+1], f[100+1];//d is discovery time, and f is finished time.
int color[100+1], time = 0, n;

int main(){
    int i, j;

    //input a adjacency list
    scanf("%d", &n);
    for(i = 1; i<=n; i++){
	scanf("%d%d",&i, &adj[i][0]);//first element of ith array store the number of adjcency vertex
	for(j = 1; j<=adj[i][0]; j++){
	    scanf("%d", &adj[i][j]);
	}
    }
    //impliment the algorithm DFS
    dfs();
    //print
    for(i = 1; i<=n; i++)
	printf("%d %d %d\n", i, d[i], f[i]);
    
    return 0;
}

void dfs( void ){
    int i, j;

    //initialization
    for(i = 0; i<=n; i++)
	    color[i] = WHITE;
    for(i = 1; i<=n; i++)
	if(color[i] == WHITE) visit(i);
    return ;
}

void visit( int u ){
    int i, j, k;

    color[u] = GRAY;
    d[u] = ++time; //discovery time
    //find undiscovered adjcency vertices 
    for(i = u,j = 1; j <= adj[i][0]; j++){
	if(color[ adj[i][j] ] == WHITE) 
	    visit( adj[i][j] );
    }
    color[u] = BLACK; //finished time
    f[u] = ++time;

    return ;
}

