#include<stdio.h>
#include<stdlib.h>

#define SIZE 101

int d[SIZE], f[SIZE], s[SIZE][SIZE];
int tim = 1; //最初に訪問する頂点の開始時刻を 1 とする                          


void DFS(int a){
  int b;

  if(d[a] == 0){
    d[a] = tim;
    tim++;

    for(b=1; s[a][b]!=-1; b++){
      if(d[s[a][b]]==0) DFS(s[a][b]);
    }

    f[a] = tim;
    tim++;
  }

}


int main(){

  int i, j, n, u, k;

  scanf("%d", &n);

  for(i=1; i<=n; i++){
    scanf("%d %d", &u, &k);

    for(j=1; j<=k; j++){
      scanf("%d", &s[i][j]);
    }

      s[i][j] = -1;

        }

  for(i=1; i<=n; i++){
    DFS(i);
    printf("%d %d %d\n", i, d[i], f[i]);
  }


return 0;
}
