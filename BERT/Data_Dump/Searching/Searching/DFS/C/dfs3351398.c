#include <stdio.h>
#define max 100
#define white 1
#define gray 2
#define black 3
typedef struct{
  int num; //頂点の番号を表す。
  int degree; //出次数を表す。
  int Adj[max]; //隣接リスト(隣接する頂点の番号のリスト)。
  int color;
  int dtime; //最初に発見された時刻を表す。
  int ftime; //隣接リストを調べ終えた完了時刻を表す。
} node;
int n, time, A[max+1][max+1];
void dfs(node *);
void visit(int, node *);

int main()
{
  //深さ優先探索のプログラム
  int i, j;
  node node[max];
  
  for(i = 0 ; i <= max ; i++){
    for(j = 0 ; j <= max ; j++) A[i][j] = 0; }

  scanf("%d",&n);

  for(i = 0 ; i < n ; i++){
    scanf("%d%d",&node[i].num,&node[i].degree);
    for(j = 0 ; j < node[i].degree ; j++){
      scanf("%d",&node[i].Adj[j]);
      A[node[i].num][node[i].Adj[j]] = 1; }
  }

  dfs(node);

  for(i = 0 ; i < n ; i++) printf("%d %d %d\n",node[i].num,node[i].dtime,node[i].ftime);
  
  return 0;
}

void dfs(node *node)
{
  int i;

  for(i = 0 ; i < n ; i++) node[i].color = white;

  time = 0;

  for(i = 0 ; i < n ; i++){
    if(node[i].color == white) visit(i, node); }
      
}

void visit(int u, node *node)
{
  int i, j, index;
  
  node[u].color = gray;
  node[u].dtime = ++time;

  for(i = 0 ; i < node[u].degree ; i++){
    for(j = 0 ; j < n ; j++){
      if(node[u].Adj[i] == node[j].num) index = j; }
    if(A[node[u].num][node[u].Adj[i]] == 1 && node[index].color == 1) visit(index, node); }
    
  node[u].color = black;
  node[u].ftime = ++time;

}
