#include <stdio.h>
#define WHITE -2
#define GRAY 0
#define BLACK 1
#define INF -1
#define N 100

typedef struct{
  int color;
  int time;
  int node;
}Data;

int a[N][N], que[N];
int n, size;
int head, tail;

Data data[N];

void bfs(int);
void enqueue(int);
int dequeue();

int main(){

  int i, j, u, k, v;

  scanf("%d",&n);
  
  for(i=0; i<n; i++){
    data[i].color= WHITE;
    data[i].time= INF;
    for(j=0; j<n; j++){
      a[i][j]=0;
    }
  }
  for(i=0; i<n; i++){
    scanf("%d %d", &u, &k);//u...頂点の番号 k...いくつ頂点が隣接してるか
    data[i].node= u;
    for(j=0; j<k; j++){
      scanf("%d", &v);
      a[u-1][v-1]= 1;
    }
  }

  bfs(0);

  //print
  for(i=0; i<n; i++){
    printf("%d %d\n", data[i].node, data[i].time);
  }

  return 0;
}

void bfs(int time){

  int u, i;
  //訪れたらGRAY. timeは1増えて、それが与えられる
  data[time].color= GRAY; //今後GRAYだとtimeはカウントされない
  data[time].time= 0;

  enqueue(time);

  while(size>0){ //中に何か入っている場合＝まだ調べるものが残っている場合

    u= dequeue(); // 先頭一つ出す=行って帰ってきて調べ終わり

    for(i=0; i<n; i++){

      if(a[u][i]== 1 && data[i].color ==WHITE){
	data[i].color=GRAY;
	data[i].time=data[u].time+1;
	enqueue(i);
      }
    }
    data[u].color=BLACK;
  }

}
void enqueue(int u){

  que[tail]= u;
  size++;
  if(tail==N) tail=0;
  else tail++;
}
int dequeue(){

  int x=0;

  x=head;
  if(head==N) head=0; //headが最後尾だった時
  else head++;
  size--;
  return que[x];
}

