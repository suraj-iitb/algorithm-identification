#include<stdio.h>
#define NIL 0
#define FIRST 1
#define SECOND 2
#define MAX 101
//NILで未訪問（houmon[データの上限最大]に０を代入）と、矢印が伸びていないところを示す（M[][]に０を代入）
//FIRST SECOND はそれぞれ訪問回数。
int datanum,M[MAX][MAX];//Mは１、０のマトリックスであり、１がそこに矢印が伸びている、０は伸びていない
int houmon[MAX],check[MAX],end[MAX],timestamp;//houmonに訪問した回数。checkに１度目に訪れた時間、endに２度目に訪れた時間。

void dfs_visit(int point){
  int i;
  houmon[point] = FIRST;
  check[point]  = ++timestamp; 
  for(i = 1;i<=datanum;i++){
    if(M[point][i] == 0)continue; //そこには矢印が伸びていないのでたどり着けないので、飛ばす。
    if(houmon[i] == NIL){//訪問回数が０回の時、dfs_visitを再帰関数で呼び出す。
      dfs_visit(i);
    }
  }
  houmon[i] = SECOND;
  end[point] = ++timestamp;
}

void dfs(){
  int i;
  for(i=1;i<=datanum;i++)houmon[i] = NIL;//houmonに訪問回数NIL=0を代入している。
  timestamp =0;//timestampに現在時刻を代入し、その値を格納。
  for(i=1;i<=datanum;i++){//絶対にスタートが１からであるので
    if(houmon[i] == NIL)dfs_visit(i);
  }
}


int main(){
  int u,k,i,j,temp;//uは頂点の番号、kはuの出字数（その点から矢印で伸びている値の数）
  scanf("%d",&datanum);
  //1から頂点番号がスタートして、そこから１ずつ続いていくので、datanum以下のデータ数正方行列（0は未使用）
  for(i=1;j<=datanum;i++)
    for(j=1;j<=datanum;j++){
      M[i][j] = NIL;//NIL = 0
    }
  for(i=0;i<datanum;i++){
    scanf(" %d %d",&u,&k);//uは頂点数、kはuの出字数
    for(j=0;j<k;j++){
      scanf("%d",&temp);//頂点から伸びている値(->の先の値)がtemp
      M[u][temp] = 1;//Mという正方行列に1,0の表を作り、１が矢印が伸びている、０は矢印が伸びていないことを示す。
    }
  }
  dfs();
  //データの出力
  for(i=1;i<=datanum;i++){
    printf("%d %d %d\n",i,check[i],end[i]);
  }
  return 0;
}

