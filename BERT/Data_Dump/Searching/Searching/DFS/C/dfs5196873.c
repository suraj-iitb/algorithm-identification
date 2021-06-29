#include<stdio.h>
#define MAX 10000

void df(int);

    int n,t=1;
    int d[MAX],f[MAX];
    int A[MAX][MAX];
    int v[MAX];

int main(){

  int i,j,k,x,y,w;

    scanf("%d", &n);
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            A[i][j] = 0;
        }
    }

    for (i = 1; i <= n; i++){
        scanf("%d%d", &x, &y);
        if(y == 0) continue;
        for (j = 1; j <= y; j++){
            scanf("%d", &w);
            A[x][w] = 1;
        }
    }

    for(i = 1; i <= n; i++)

      v[i] = 0;

    for(i = 1; i <= n; i++){
        if(v[i] == 0)
          df(i);
    }

    for(i = 1; i <= n; i++){
        printf("%d %d %d\n",i,d[i],f[i]);
    }

    return 0;
}

void df(int i){
    int j;
    v[i] = 1;
    d[i] = t++;
    for(j = 1;j <= n; j++){
        if(A[i][j] == 0)
          continue;
        if(v[j] == 0)
          df(j);
    }
    v[i] = 2;
    f[i] = t++;
}

