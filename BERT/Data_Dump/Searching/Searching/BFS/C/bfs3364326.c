#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 101
#define NIL 0
#define NONE (-3)
#define FIRST 1
#define SECOND 2
int d[MAX],M[MAX][MAX],queue[MAX],head,tail,datanum;//Mは隣接しているかの確認。dは頂点からの距離。distance headはint mainの一番最初に初期化
void q_push(int n){
  queue[head++] = n;
}
int q_pop(){
  int temp = queue[tail++];
  return temp;
}

void bfs(int first){
  int i,j;
  for(i=1;i<=datanum;i++){
    d[i] = NONE;//NONE = -3 何も入っていない状態
  }
  d[first] = 0;
  q_push(first);
  while(head != tail){
    i = q_pop();
      for(j=1;j<=datanum;j++){
	if(d[j] != NONE)continue;
	if(d[i] == NONE)continue;
	if(M[i][j] == 0)continue;
	if(i == j)continue;
	d[j] = d[i] + 1;
	q_push(j);
      }
  }  
}

int main(){
  int i,j,k,id,u,v,temp;//idは頂点の番号。uは出字数。tempは隣接する頂点の番号
  head = tail = 0;
  scanf("%d",&datanum);
  for(i=1;i<=datanum;i++)
    for(j=1;j<=datanum;j++){
      M[i][j] = 0;
    }
  for(i=0;i<datanum;i++){
    scanf(" %d %d",&id,&u);
    for(j=0;j<u;j++){
      scanf(" %d",&temp);
      M[id][temp] = 1;
    }
  }
  bfs(1);//1からスタート
  for(i=1;i<=datanum;i++){
    printf("%d",i);
    if(d[i] == NONE)printf(" -1\n");
    else printf(" %d\n",d[i]);
      }
 
  return 0;
}

