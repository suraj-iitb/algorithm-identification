#include<stdio.h>
#define WHITE 0
#define GRAY -1
#define BLACK -2

typedef struct{
  int u;
  int k;
  int v[10];
  int vi;
  int d;
  int f;
}DFS;

int S[101];
int time = 0;
int color[101];
int top = 0;

void push(int a){
  S[top] = a;
  top++;
  color[a] = GRAY;
}

void pop(){
  top--;
}

int main()
{
  int i,j,n,p;
  
  scanf("%d",&n);
  
  DFS a[n+1];
  
  for(i=1; i<=n; i++){
    scanf("%d%d",&a[i].u,&a[i].k);
    a[i].d = 0;
    a[i].f = 0;
    a[i].vi = 0;
    color[i] = WHITE;
    for(j=0; j<a[i].k; j++){
      scanf("%d",&a[i].v[j]);
    }
  }
  
  for(i=1; i<=n; i++){
    if(color[i] == WHITE){
      push(a[i].u);
      a[i].d = ++time;
      while(1){
	if(top == 0)  break;
	
	p = S[top-1];
	
	if(a[p].k != 0 && a[p].vi < a[p].k){
	  if(color[a[p].v[a[p].vi]] == WHITE){
	    push(a[p].v[a[p].vi]);
	    a[a[p].v[a[p].vi]].d = ++time;
	  }
	  a[p].vi++;
	}
	
	
	else{
	  pop();
	  color[p] = BLACK;
	  a[p].f = ++time;
	}
      }
    }
  }
  
  for(i=1; i<=n; i++){
    printf("%d %d %d\n",a[i].u,a[i].d,a[i].f);
  }
  return 0;
}
