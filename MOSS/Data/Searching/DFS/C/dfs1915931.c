#include<stdio.h>
#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n,arr[N][N];
int col[N],d[N],f[N],time;

void dfs(void);
void visit(int);

int main(){
  int i,j ,a,b,c;
    scanf("%d",&n);
  

  for(i =0;i<n;i++)
    for(j =0;j<n;j++)
      arr[i][j]=0;

  for(i =0;i<n;i++){
    scanf("%d %d",&a,&c);
    a--;
    for(j =0;j<c;j++){
      scanf("%d",&b);
      b--;
      arr[a][b] = 1;
    }
  }
  dfs();
  return 0;
}
  void dfs() {
    int a ;
    for(a=0;a<n;a++)
      col[a] = WHITE;
    time = 0;
    for(a=0;a<n;a++)
      if(col[a] == WHITE) 
	visit(a);
    for(a=0;a<n;a++)
      printf("%d %d %d\n",a+1,d[a],f[a]);
  }

  void visit(int r){
    int b;
    col[r]=GRAY;
    d[r]= ++time ;
    for(b=0;b<n;b++){
      if(arr[r][b] == 0)continue;
      if(col[b]==WHITE) visit(b);
    }
    col[r]=BLACK;
    f[r] = ++time;
  }
               
