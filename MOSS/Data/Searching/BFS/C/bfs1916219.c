#include <stdio.h>
#define N 1000000
int dequeue(void);
void enqueue(int);
void visit(int);
int n,adj[101][101],d[101],time,p[N],head,tail;
char color[101];
int main(){  
  int i,j,a,b,u,v;
  scanf("%d",&n);
 
  for(i=1;i<=n;i++) {
    scanf("%d%d",&a,&b);    
    for(j=1;j<=b;j++)
      scanf("%d",&adj[a][j]);
  }
  
 

    for(j=1;j<=n;j++){

      color[j] = 'W';
      d[j] = -1;
    }
    

    color[1] = 'G';
    d[1] = 0;
    head=tail =1;
    enqueue(1);

    while( head!=tail){
      u = dequeue();
      for(j=1;j<=n;j++){
	if(adj[u][j]!=0){
	  v=adj[u][j];
	  if (color[v] == 'W'){
	    color[v] = 'G';
	    d[v] = d[u] + 1;
	    enqueue(v);
	  }
	}

      }
    }
      color[u] = 'B';
    


  

for(i=1;i<=n;i++)
  printf("%d %d\n",i,d[i]);
  return 0;
}



int dequeue(void){
  int x;
  x = p[head];
  if (head + 1 == N)
    head = 0;
  else head = head + 1;
  return x;

}
void enqueue(int x){
  p[tail] = x;
  if(tail + 1 == N)
    tail = 0;
  else tail = tail + 1;
}
