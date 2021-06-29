#include <stdio.h>

void bfs(int *,int);
void enqueue(int *q,int*pb,int key){

  q[*pb]=key;
  if(++(*pb)==101) *pb=0;
}

int dequeue(int *q,int *pf){

  if(*pf==100) *pf=0;
  return q[(*pf)++];
}
  

int graph[101][101];

int main(){
  int i,j,n,roop,key1,key2,d[101];

  scanf("%d",&n);
  
  for(i=1;i<101;i++){
    for(j=1;j<101;j++){
      graph[i][j]=0;
    }
  }

  
  for(i=1;i<=n;i++){
    scanf("%d%d",&key1,&roop);

    for(j=0;j<roop;j++){
      scanf("%d",&key2);

      graph[key1][key2]=1;
    }
    d[i]=-1;
  }

  bfs(d,n);

  for(i=1;i<=n;i++) printf("%d %d\n",i,d[i]);

  return 0;
}

void bfs(int *d,int n){
  int i,j,color[101],q[101],pf=0,pb=0,key;

  enqueue(q,&pb,1);
  for(i=2;i<=n;i++) color[i]=1;
  color[1]=0;
  d[1]=0;

  while(pf!=pb){
    key=dequeue(q,&pf);
    
    for(i=1;i<=n;i++){

      if(graph[key][i] && color[i]){
	enqueue(q,&pb,i);
	color[i]=0;
	d[i]=d[key]+1;
      }
    }

    
  }
  
}
    
      

