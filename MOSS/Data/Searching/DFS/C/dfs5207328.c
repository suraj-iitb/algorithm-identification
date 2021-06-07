#include<stdio.h>
#define BLA 0
#define GRA 1
#define WHI 2

void dfs(void);
void vis(int);

int G[101][101];
int n, ti, col[101], fir[101], end[101];

int main(){
    int i, j;
    int k, l, m;
    
    scanf("%d", &n);
    for(i=1 ; i<n+1 ; i++){
        for(j=1 ; j<n+1 ; j++){
            G[i][j] = 0;
        }
    }
    
    for(i=0 ; i<n ; i++){
        scanf("%d %d", &k, &m);
        for(j=0 ; j<m ; j++){
            scanf("%d", &l);
            G[k][l] = 1;
        }
    }
    
    dfs();
    
    for(i=1 ; i<n+1 ; i++){
        printf("%d %d %d\n", i, fir[i], end[i]);
    } 
    
    return 0;
}

void dfs(){
    int i;
    for(i=1 ; i<n+1 ; i++){
        col[i] = WHI;
    }
    ti = 0;
    for(i=1 ; i<n+1 ; i++){
        if(col[i] == WHI){
            vis(i);
        }
    }
}

void vis(int i){
    int j;
    col[i] = GRA;
    fir[i] = ++ti;
    for(j=1 ; j<n+1 ; j++){
        if(G[i][j] == 0){
            continue;
        }
        if(col[j] == WHI){
            vis(j);
        }
    }
    col[i] = BLA;
    end[i] = ++ti;
}
