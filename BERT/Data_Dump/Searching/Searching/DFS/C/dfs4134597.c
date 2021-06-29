#include<stdio.h>

#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int a,t,top;
int A[MAX][MAX],B[MAX],C[MAX],color[MAX],S[MAX];

int next(int);
void push(int);
int pop();
void visit(int);
void dfs();


int main()
{
  int i,j,s,t,u;
  
  scanf("%d",&a);

  for(i=0;i<a;i++){
    scanf("%d %d",&t,&s);
    for(j=0;j<s;j++){
      scanf("%d",&u);
      A[t][u]=1;
    }
  }
  
  dfs();
  
  for(i=1;i<=a;i++){
    printf("%d %d %d\n",i,B[i],C[i]);
  }
  
  return 0;
}


int next(int x)
{
  int i;
  
  for(i=1;i<=a;i++){
    if(A[x][i]==1 && color[i]==WHITE){
      return i;
    }
  }
  
  return 0;
}


void push(int x)
{
  S[top++]=x;
}


int pop()
{
  return S[top--];
}


void visit(int r)
{
  int i;
  
  push(r);
  color[r]=GRAY;
  B[r]=++t;

  while(top!=0){
    int a=S[top-1],b;
    b=next(a);
    if(b!=0){
      if(color[b]==WHITE){
	push(b);
	color[b]=GRAY;
	B[b]=++t;
      }
    }
    else {
      pop();
      color[a]=BLACK;
      C[a]=++t;
    }
  }
}


void dfs()
{
  int i;
  
  for(i=1;i<=a;i++){
    if(color[i]==WHITE){
      visit(i);
    }
  }
}


