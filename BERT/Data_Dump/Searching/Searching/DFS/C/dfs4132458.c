#include <stdio.h>
#define MAX 100
#define UNEXPLORED 0
#define FIRST_TIME 1
#define SECOND_TIME 2

int A[MAX][MAX];
int n, d[MAX], f[MAX], time, judge[MAX];
//d:1回目の時刻
//f:2回目の時刻
//time:時間測定
//judge:訪問した回数の記録

void dep_search(int u){
  int v;
  judge[u] = FIRST_TIME;
  d[u] = time++;
  for(v = 0; v < n; v++){
    if(A[u][v] == 0) continue;
    if(judge[v] == UNEXPLORED){
      dep_search(v);
    }
  }
  judge[u] = SECOND_TIME;
  f[u] = time++;
}

void depth(){
  int u;
  for(u = 0; u < n; u++){
    judge[u] = UNEXPLORED;
  }
  time = 1;

  for(u = 0; u < n; u++){
    if(judge[u] == UNEXPLORED){
      dep_search(u);
    }
  }

  for(u = 0; u < n; u++){
    printf("%d %d %d\n",u+1, d[u], f[u]);
  }
  
}

void Counting(int num, int data){
  A[num-1][data-1] = 1;
}

int main(){
  int i, j, k, num, data;

  scanf("%d",&n);
  //配列の初期化
  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      A[i][j] = 0;
    }
  }
  
  //頂点の番号・出次数（接している頂点の数）を入力
  for(i = 0; i < n; i++){
    scanf("%d %d",&num, &k);
    if(k == 0) continue;
    else{
      //隣接する頂点を入力
      for(j = 0; j < k; j++){
        scanf("%d",&data);
        Counting(num, data);
      }
    } 
  }
  
  //深さ探索
  depth();
  
  //データ出力
  
  return 0;
}

