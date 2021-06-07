#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
void dfs();
void visit(int);
int A[101][101];
int Ans[101][2];
int color[101];
int n;
int time;
int main(){
    int i,j,num,d,x;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&num,&d);
        for(j=0;j<d;j++){
            scanf("%d",&x);
            A[num][x]=1;
            
        }
    }
  
    dfs();
    for(i=1;i<=n;i++){
        
      printf("%d %d %d\n",i,Ans[i][0],Ans[i][1]);
    }
    return 0;
}
void dfs(){
    int i;
    time=0;
    for(i=1;i<=n;i++){
   
        if(color[i]==WHITE){
        visit(i);
    }
    }
}
void visit(int u){
    int next,i;

    color[u]=GRAY;
    Ans[u][0]=++time;
    
for(i=0;i<=n;i++){
    if(A[u][i]!=0){
    if(color[i]==WHITE){
        visit(i);
        
    }
    }
}
    color[u]=BLACK;
    Ans[u][1]=++time;
}

