#include <stdio.h>
#define n_max 101
void push(int);
int pop();
void bfs(int);

int queue[1000];
int n,head=0,tail=0;
int adj[n_max][n_max];
int d[n_max],used[n_max];

int main(){
  int i,j;
  int u,k,num;
  
  scanf("%d",&n);//ヴァーテックスの数
  for(i=1;i<=n;i++){
    scanf("%d %d",&u,&k);//頂点のナンバーと、その頂点からのびる線の数
    for(j=0;j<k;j++){
      scanf("%d",&num);
      adj[u][num]=1;
    }
  }

  for(i=1;i<=n;i++)d[i]=0;//すべてのdを初期化
  
  bfs(1);
  for(i=2;i<=n;i++){
    if(d[i]==0)d[i]=-1;
  }
  
  for(i=1;i<=n;i++) printf("%d %d\n",i,d[i]);
  
  return 0;
}


void push(int x){
  queue[head]=x;
  head++;
}

int pop(){
  int x;
  x=queue[tail];
  tail++;
  return x;
}

void bfs(int x){
  int i,p;
  
  push(x);
  used[x]=1;
  while(head!=tail){
    p=pop();
    for(i=1;i<=n;i++){
      if(adj[p][i]==1 && used[i]==0){
	push(i);
	d[i]=d[p]+1;
	used[i]=1;
      }
    }
  }
}

