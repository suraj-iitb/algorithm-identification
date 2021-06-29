#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct{
  int id;
  int d;
  int k;
  int *A;
  int color;
} Point;

Point *p;
int n,i,j,v,*queue,x=0,head=0,tail=0,LEN=0;

void enqueue(int x){
  queue[tail++]=x;
  if(tail>LEN) tail=0;
}

int dequeue(){
  int x;
  if(head!=tail){
  x=queue[head++];
  if(head>LEN) head=0;
  return x;
  }
  return -1;
}

void search(int u){
  p[u].color=0;
  p[u].d=0;
  enqueue(u);

  while(head!=tail){
    u=dequeue();

    for(v=0;v<p[u].k;v++) if(p[ p[u].A[v] ].color==-1){
	p[ p[u].A[v] ].color=0;
	p[ p[u].A[v] ].d=p[u].d+1;
	enqueue( p[u].A[v] );	
    }
    
    p[u].color=1;
  }
  
}

int main(){

  scanf("%d",&n);

  p = (Point *) malloc (sizeof( Point )*n);

  for(i=0;i<n;i++){
    scanf("%d%d",&p[i].id,&p[i].k);
    
    p[i].A=(int *)malloc(sizeof(int) * p[i].k);
    LEN+=p[i].k;

    p[i].color=-1;
    p[i].d=INT_MAX;
    
    for(j=0;j<p[i].k;j++){
      scanf("%d",&p[i].A[j]);
      p[i].A[j]--;      
    }
    
  }

  LEN++;
  queue=(int *)malloc(sizeof(int)*LEN);

  search(0);
  for(i=0;i<n;i++) printf("%d %d\n",p[i].id,(p[i].d==INT_MAX) ? (-1) : p[i].d);
  
  return 0;
}

