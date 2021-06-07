#include <stdio.h>
#define max 100
#define INF 2147483647 
#define white 1
#define gray 2
#define black 3
typedef struct{
  int num; //頂点の番号を表す。
  int degree; //出次数を表す。
  int Adj[max]; //隣接リスト(隣接する頂点の番号のリスト)。
  int color;
  int d; //頂点1からその頂点までの距離を表す。
} node;
void enqueue(int);
int dequeue(void);
void bfs(node *, int);
int n, time, A[max+1][max+1];
int queue[max], head = 0, tail = 0;

int main()
{
  //幅優先探索のプログラム。
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

  bfs(node, 0);

  for(i = 0 ; i < n ; i++){
    if(node[i].d == INF) node[i].d = -1; //頂点1からたどり着けなかった頂点の距離を-1とする。
    printf("%d %d\n",node[i].num,node[i].d); }
  
  return 0;
}

void enqueue(int num)
{
  int next;

  next = (tail + 1) % max;
  
  if(next != head){
    queue[tail] = num;
    tail = next; }

}

int dequeue(void)
{
  int de = INF;

  if(head != tail){
    de = queue[head];
    head = (head + 1) % max;
    return de; }

  return de;
}

void bfs(node *node, int s)
{
  int i, j, u, index;

  for(i = 0 ; i < n ; i++){
    node[i].color = white;
    node[i].d = INF; }

  node[s].color = gray;
  node[s].d = 0;

  head = tail; //キューを空っぽにする。
  enqueue(s);

  while(head != tail){ //キューが空っぽになるまで
    u = dequeue();
    for(i = 0 ; i < node[u].degree ; i++){ 
      for(j = 0 ; j < n ; j++){ 
	if(node[u].Adj[i] == node[j].num) index = j; }
      if(node[index].color == white && A[node[u].num][node[index].num] == 1){
	node[index].color = gray;
	node[index].d = node[u].d + 1;
	enqueue(index); }
    }
    node[u].color = black; }
	
}
