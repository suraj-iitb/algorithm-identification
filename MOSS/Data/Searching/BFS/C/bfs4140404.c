#include <stdio.h>
#define N 100

void dfs(void);
void visit(int,int);

int n,a[N][N],color[N],d[N],t; //d=start

int main(){
  int i,j,k,x,u;

  scanf("%d",&n);
  for(i = 0;i < n;i++){
    for(j = 0;j < n;j++){
      a[i][j] = 0;
    }
  }
  for(i = 0;i < n;i++){
    scanf("%d %d",&u,&k);
    u--;
    for(j = 0;j < k;j++){ //x=連結
      scanf("%d",&x);
      x--;
      a[u][x] = 1;
    }
  }

  dfs();

  for(i = 0;i < n;i++){
    if(d[i] == 10000000) printf("%d %d\n",i+1,-1);
    else printf("%d %d\n",i+1,d[i]);
  }
 
  return 0;
}

void dfs(void){
  int s,i,u,con;

  for(u = 0;u < n;u++){
    color[u] = 0; //0=白
    d[u] = 10000000;
  }
  color[0] = 1;
  t=0;
  s=0;
  d[0] = 0;
  while(1){
    if(s == n) break;
    if(color[s] == 1){ //1=灰
      for(i = 0;i < n;i++){
	if(a[s][i] == 1){
	  color[i] = 1;
	  if(d[i]>t+1){
	    d[i] = t+1;
	    con = d[i];
	    visit(i,con);
	  }
	}
      }
      color[s] = 2; //2=黒
      s++;
      t=d[s];
      if(color[s] == 0 ){
	while(color[s] == 0){
	  if(s==n)break;
	  s++;
	  t=d[s];
	}
      }	
      con++;
    }
  }
  //t--; 0,1,3,2
  
}

void visit(int s,int t){
  int i,con;
  for(i = 0;i < n;i++){
    if(a[s][i] == 1){
      color[i] = 1;
      if(d[i]>t+1){
	d[i] = t+1;
	con=d[i];
	visit(i,con);
      }
    }
  }
}

