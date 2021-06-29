#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int id;
  int d;
  int dd;
  int f;
  int k;
  int *A;
  int color;
} Point;

Point *p;
int n,i,j,id,t=0,*stack,x=0,top=0;

void insert(int u){
  stack[++top]=u;
}

void search(int u){
  int v;
  insert(u);
  p[u].color=0;
  p[u].d=++t;

  while(top!=0){
    u=stack[top];
    v=p[u].A[ p[u].f ];
    
    if(p[u].f<p[u].k){
      if(p[v].color==-1){
	p[v].color=0;
	p[v].d=++t;
	insert(v); }
    }
    else{
      top--;
      p[u].color=1;
      p[u].dd=++t;
    }
    
    p[u].f++;
    //printf("u=%d, v=%d, k=%d, f=%d, t=%d\n",u,v,p[u].f,p[u].k,t);
  }
  
}

int main(){

  scanf("%d",&n);

  p = (Point *) malloc (sizeof( Point )*n);

  for(i=0;i<n;i++){
    scanf("%d%d",&p[i].id,&p[i].k);
    
    p[i].A=(int *)malloc(sizeof(int) * p[i].k);
    top+=p[i].k;

    p[i].f=0;
    p[i].color=-1;
    
    for(j=0;j<p[i].k;j++){
      //printf("x=%d, k=%d --",x++,p[i].k);
      scanf("%d",&p[i].A[j]);
      p[i].A[j]--;
      
      //printf(" p[%d].A[%d]=%d ||",i,j,p[i].A[j]);
    }
    //printf("\n");
    
  }

  stack=(int *)malloc(sizeof(int)*top);
  top=0;

  for(i=0;i<n;i++) if(p[i].color==-1) search(i);
  for(i=0;i<n;i++) printf("%d %d %d\n",p[i].id,p[i].d,p[i].dd);
  
  return 0;
}

