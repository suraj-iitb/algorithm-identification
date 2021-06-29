#include<stdio.h>

int d[101],f[101],g[101][101],n;
int t = 1 ;

void visit(int i){

  int l,m;
  
  d[i] = t++;
  
  for(l = 1 ; l <= n ; l++ ){
    if(g[i][l] == 1 && d[l] == 0){
      visit(l);
    } 
  }
  
  f[i] = t++;
}

int main(void){
  
  int i,j,u,k,x;


  scanf("%d",&n);

  // 初期化
  for(i = 1 ; i <= n ; i++){
    d[i] = 0;
    f[i] = 0; 
    for(j = 1 ; j <= n ; j++ ){
      g[i][j] = 0;
    }
  }

  // 入力
  for(i = 0 ; i < n ; i++){
    scanf("%d%d",&u,&k);
    for(j = 0 ; j < k ; j++ ){
      scanf("%d",&x);
      g[u][x] = 1;
    }
  }
  /*  
  // 仮出力
  printf("隣接行列\n");

  for(i = 1 ; i <= n ; i++){
    for(j = 1 ; j <= n ; j++ ){
      if(j != 1) printf(" ");
      printf("%d",g[i][j]);
    }
    printf("\n");
  }
  */
  // 深さ優先探索

  
  for(i = 1 ; i <= n ; i++ ){
      
    if(d[i] == 0 ){
      visit(i);

    }
  }
    
    
  // 出力

  for(i = 1 ; i <= n ; i++ ){
    printf("%d %d %d\n",i,d[i],f[i]);
    
  }
    
  return 0;
}
