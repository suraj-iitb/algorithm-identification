#include<stdio.h>
#include<stdlib.h>
int n,a,b;
int* t[100];
int  u[100];
int visited[100];

int v[300],v2[300];
int l=0,r=0,cnt=1;

void push(int x,int y){
  v[r]=x;
  v2[r]=y;
  r++;
}

void pop(){
  l++;
}

int main(){
  int i,j;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a);
    a--;
    scanf("%d",&u[a]);
    t[a]=malloc( sizeof(int) * u[a] );
    for(j=0;j<u[a];j++){
      scanf("%d",&t[a][j]);
      t[a][j]--;
    }
    visited[i]=-1;
  }

   
  push(0,0);
  visited[0]=0;
  while(l!=r){
    a=v[l];
    b=v2[l];
    pop();
    for(i=0;i<u[a];i++){
      if(visited[t[a][i]]==-1){
	push(t[a][i],b+1);
	visited[t[a][i]]=b+1;
      }
    }
  }
  
    
  for(i=0;i<n;i++){
    printf("%d %d\n",i+1,visited[i]);
  }
  return 0;
}
