#include<stdio.h>
#define N 100
#define WHITE 0//未訪問の頂点
#define GRAY  1//現在訪問中
#define BLACK 2//訪問を完了済
int A[N][N];
int S[N],d[N],f[N],color[N];
int top=0,n;
int t;//記録
//深さ優先探索                                                                  
void visit(int u)
{
  int i;
  color[u]=GRAY;//1                                                             
  d[u]=++t;//最初の訪問                                                      
  for(i=0;i<n;i++)
    {
      if(A[u][i]==0)continue;
      if(color[i]==WHITE)visit(i);                                           
    }
  color[u]=BLACK;                                                            
  f[u]=++t;//訪問完                                                        
}
int main(){
  int i,j;
  int u;//頂点の番号                                                            
  int v;//uに隣接する頂点の番号                                                 
  int k;//頂点から出ていく個数                                                
  scanf("%d",&n);//4                                                            
  /*初期化*/
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
        {
          A[i][j]=0;
        }
    }
  for(i=0;i<n;i++)
    {
      scanf("%d",&u);
      scanf("%d",&k);
      u--;
      for(j=0;j<k;j++)
        {
          scanf("%d",&v);
          v--;
          A[u][v]=1;
        }
    }
      /*初期化*/
  for(u=0;u<n;u++)
    {
      color[u]=WHITE;
    }
  t=0;
  for(u=0;u<n;u++)
    {
      if(color[u]==WHITE)visit(u);                                           
    }
  for(u=0;u<n;u++)
    {
      printf("%d %d %d\n",u+1,d[u],f[u]);
    }
  return 0;
}

