#include<stdio.h>

int map[101][101];
int d[101];
int queue[101];
int n;

int main(){
    int i, j;
    int u, o, a;
    scanf("%d", &n);
    for( i = 1; i <= n; i++ ){
        d[i] = -1;
        for( j = 1; j <= n; j++ ){
            map[i][j] = 0;
        }
    }
    for( i = 1; i <= n; i++ ){
        scanf("%d", &u);
        scanf("%d", &o);
        for( j = 0; j < o; j++ ){
            scanf("%d", &a);
            map[i][a] = 1;
        }
    }

    int ppp=0, xxx=0;
    queue[xxx++] = 1;
    d[1] = 0;
    while( ppp < xxx ){
        i = queue[ppp++];
        for( j = 1; j < n+1; j++ ){
            if( map[i][j] == 1 && d[j] == -1 ){
                queue[xxx++] = j;
                d[j] = d[i]+1;
            }
        }
    }

    for( i = 1; i <= n; i++ ){
        printf("%d %d\n", i, d[i]);
    }
}

