#include <stdio.h>
 
#define N 102
#define WHITE 0
#define GRAY 1
#define BLUE 2
#define INF 1000000
 
int n,adj[N][N],color[N],d[N],Q[N],head=1,tail=1;
 
int Queempty(){
  if (head==tail){
    return 1;
  } else {
    return 0;
  }
}
 
void Enqueue(int r){
  int i;
  Q[tail] = r;
  tail++;
}
 
int Dequeue(){
  int i;
  i = Q[head];
  Q[head] = -1;
  head++;
  return i;
}
 
void BFS(int s){
  int u,v;
  color[s]=GRAY;
  d[s]=0;
  Enqueue(s);
  while(Queempty()==0){
    u = Dequeue();
    for (v=1;v<=n;v++){
      if (color[v]==WHITE&&adj[u][v]==1){
	color[v]=GRAY;
	d[v]=d[u]+1;
	Enqueue(v);
      }
    }
    color[u]=BLUE;
  }
   
}
 
int main() {
  int i,j,u,k,v,s=1;
  
  for (i=1;i<N;i++){
    for (j=1;j<N;j++){
      adj[i][j]=0;
    }
    Q[i]=-1;
    color[i]=WHITE;
    d[i]=INF;
  }
  
 
  scanf ("%d",&n);
  for (i=1;i<=n;i++){
    scanf ("%d%d",&u,&k);
    for (j=1;j<=k;j++){
      scanf("%d",&v);
      adj[u][v]=1;
    }
  }
 
  BFS(s);
  for (i=1;i<=n;i++){
    if (d[i]==INF) {
      d[i]=-1;
    }
    printf("%d %d\n",i,d[i]);
  }
  return 0;
}


		


/*幅優先探索

与えられた有向グラフ G=(V,E)
について、頂点 1 から各頂点への最短距離 d（パス上の辺の数の最小値）を求めるプログラムを作成してください。各頂点には 1 から n までの番号がふられているものとします。頂点 1

からたどり着けない頂点については、距離として-1 を出力してください。
入力

最初の行に G
の頂点数 n が与えられます。続く n 行で各頂点 u

の隣接リストが以下の形式で与えられます：

u
k v1 v2 ... vk

u
は頂点の番号、k は u の出次数、v1v2...vk　は u

に隣接する頂点の番号を示します。
制約

    1≤n≤100

出力

各頂点について id
、d を１行に出力してください。id は頂点の番号、d は頂点 1

からその頂点までの距離を示します。頂点番号順に出力してください。
入力例 1

4
1 2 2 4
2 1 4
3 0
4 1 3

出力例 1

1 0
2 1
3 2
4 1
*/

