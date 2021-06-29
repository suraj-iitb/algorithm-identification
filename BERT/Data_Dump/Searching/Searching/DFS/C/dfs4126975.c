#include <stdio.h>
#define WHITE 0
#define BLACK 2
#define GRAY 1

void dfs(void);
void visitdfs(int);


int n, d[200], f[200], color[100] ,a[100][100];
int totalcount=0;

int main(){

  int i, j, k, u, v;

  scanf("%d", &n);

  for(i=0; i<n; i++){
    for(j=0; j<n; j++){
      a[i][j]=0;
    }
  }
  for(i=0; i<n; i++){
    scanf("%d %d", &u, &k);//u...頂点の番号 k...いくつ頂点が隣接してるか

    for(j=0; j<k; j++){
      scanf("%d", &v);
      a[u-1][v-1]=1;
    }
  }

  dfs();

  //print
  for(u=0; u<n; u++){
    printf("%d %d %d\n",u+1, d[u], f[u]); 
  }

  return 0;
}

void dfs(){

  int u;//uは頂点番号

  //まず全部をWHITEにする
  for(u=0; u<n; u++){
    color[u]=WHITE;
  }

  //WHITEな頂点を訪れる
  for(u=0; u<n; u++){
    if(color[u]==WHITE){

      visitdfs(u);
    }
  }

}
void visitdfs(int u){

  int v; // vはuの次の頂点

  //訪れたのでまずはGRAYになる。countは1増える
  color[u]=GRAY;

  totalcount++;

  d[u]=totalcount;

  for(v=0; v<n; v++){
    if(a[u][v]==0) continue; //0..つまり継承関係にない場合
    if(color[v]==WHITE) visitdfs(v);
  }

  color[u]=BLACK;
  totalcount++;
  f[u]=totalcount;
}


