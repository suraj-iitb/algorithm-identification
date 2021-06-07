#include<stdio.h>
#include<stdlib.h>
int n,a;
int* t[100];
int  u[100];
int  begin[100];
int  end[100];
int visited[100];

int v[100];
int w=0,cnt=1;

void push(int x){
  v[w]=x;
  w++;
}

void pop(){
  w--;
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
  }
  for(j=0;j<n;j++){
    if(visited[j]==1)continue;
    push(j);
    while(w!=0){
      a=v[w-1];
      if(visited[a]==0)begin[a]=cnt++;
      visited[a]=1;
      for(i=0;i<u[a];i++){
	if(visited[t[a][i]]==0){
	  push(t[a][i]);
	  break;
	}
      }
      if(i==u[a]){
	end[a]=cnt++;
	pop();
      }
    }
  }
    
  for(i=0;i<n;i++){
    printf("%d %d %d\n",i+1,begin[i],end[i]);
  }
  return 0;
}
