#include <stdio.h>

void dfs(int*,int*,int);
void visit(int*,int*,int*,int,int*,int);
void push(int *S,int *p,int key){
  (*p)++;
  S[*p]=key;
}
  
int pop(int *S,int *p){
  (*p)--;
  return S[*p+1];
}

int graph[101][101];
  

int main(){
  int i,j,key1,key2,roop,n,d[101],f[101];

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      graph[i][j]=0;
    }
  }
 

  for(i=1;i<=n;i++){
    scanf("%d%d",&key1,&roop);

    for(j=1;j<=roop;j++){
      scanf("%d",&key2);

      graph[key1][key2]=1;
    }
  }

  /*
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      printf(" %d",graph[i][j]);
    }
    printf("\n");
  }
  */
  

  dfs(d,f,n);

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  
  return 0;
}

void dfs(int *d,int *f,int n){
  int u,color[101],time=0;

  for(u=1;u<=n;u++) color[u]=1;

  for(u=1;u<=n;u++){
    
    if(color[u]) visit(d,f,color,n,&time,u);
  }
  
}

void visit(int *d,int *f,int *color,int n,int *time,int key){
  int i,j,S[101],p=-1,u,v;
  
  push(S,&p,key);
  color[key]=0;
  d[key]= ++(*time);

  
  while(p!=-1){
    //u=pop(S,&p);
    u=S[p];
    
    
    v=0;
    for(i=1;i<=n;i++){
      if(graph[u][i]==1 && color[i]==1){//ここが違う！
	v=i;
	break;
      }
    }
    
    if(v){
      push(S,&p,v);
      color[v]=0;
      d[v]=++(*time);
    }
    else{
      pop(S,&p);
      f[u]=++(*time);
    }

  }

}

