#define N 101
 
int G[N][N],way[N],chi[N],n;
 
void Fsearch(int x, int y){
  int i;
  way[x] = y;
  for(i=1;i<=chi[x];i++)
    if(y+1<way[G[x][i]]) Fsearch(G[x][i], y + 1);
}
 
int main(){
  int i,j,m;
 
  scanf("%d",&n);
 
  for(i=1;i<=n;i++){
    way[i]=N;
    scanf("%d",&m);
    scanf("%d",&chi[m]);
 
    for(j=1;j<=chi[m];j++){
	 scanf("%d",&G[m][j]);
    }
  }
 
  Fsearch(1,0);
 
  for(i=1;i<=n;i++)
    if(way[i]==N)way[i]=-1;
 
  for(i=1;i<=n;i++) printf("%d %d\n",i,way[i]);
 
  return 0;
}
