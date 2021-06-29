#include<stdio.h>
#define N 100

typedef struct{
  int k;
  int v[N];
}graph;

void push(int);
int pop(void);
int min(graph);

int stack[N], d[N+1], f[N+1];
int head=0;

int main(){
  int Min=0, n, u, i, j, cnt=1, m;
  graph G[N+1];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&u);
    scanf("%d",&G[u].k);
    for(j=0;j<G[u].k;j++){
      scanf("%d",&G[u].v[j]);
    }
  }

  for(i=1;i<N+1;i++)
    d[i]=0;
  
  push(1);
  d[1]=cnt;
  cnt++;
  m=min(G[1]);
  if(m==0){
    f[m]=cnt;
    m = pop();
    cnt++;
  }
  while(1){
    Min=0;
    while(head!=0){
      if(d[m]==0){
	push(m);
	d[m]=cnt;
	cnt++;
	continue;
      }
      m=min(G[m]);
      if(m==0){
	m = pop();
	if (0==min(G[m])){
	  f[m]=cnt;
	  cnt++;
	  continue;
	}else push(m);
      }
    }
    for(i=1;i<=n;i++){
      if(d[i]==0){
	if(Min==0||Min>i)Min=i;
      }
    }
    if(Min==0)break;
    else {
      push(Min);
      d[Min]=cnt;
      cnt++;
      m=min(G[Min]);
    }
  }
  
  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}

void push(int n){
  stack[head]=n;
  head++;
}

int pop(void){
  int n;
  n = stack[head-1];
  head--;
  return n;
}

int min(graph g){
  int i, m = 0, flag=0;
  if(g.k==0) return 0;
  for(i=0;i<g.k;i++){
    if(d[g.v[i]]==0){
      if(flag==0){
	m=g.v[i];
	flag=1;
      }else if(m>g.v[i]) m = g.v[i];
    }
  }
  return m;
}

