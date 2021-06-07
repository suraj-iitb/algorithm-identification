#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define WHITE 0
#define GRAY 1
#define BLACK -2
#define null -1

int mat[100][100];
int stack[100];
int top=0;
int n;
int color[101];
int timer;
int d[101];
int f[101];

int isempty();
void push(int);
int pop();
int matrix(int,int,int[][100]);
int next(int);
int istop();
void dfs();
void visit(int);

int main()
{
  int u,k,v[100][100],i,j;

  for(i=0;i<100;i++)
    {
      for(j=0;j<100;j++)
	{
	  v[i][j]=0;
	}
    }
  scanf("%d",&n);
  for(i=0;i<n;i++)
    {
      scanf("%d%d",&u,&k);
  
      for(j=0;j<k;j++)
	{
	  scanf("%d",&v[i][j]);
	}
    }
  matrix(n,k,v);
  dfs();
  
  
  for(i=1;i<=n;i++)
    {
      printf("%d %d %d",i,d[i],f[i]);
      printf("\n");
    }
  return 0;
}

int isempty()
{
  
  if(top==0)
    {
      return TRUE;
    }
  else return FALSE;
}

void push(int u)
{
  stack[++top]=u;
}

int pop()
{
  int res;
  if(isempty())
    {
      printf("underflow");
    }
  else
    {
      res=stack[top];
      top=top-1;
    }
  return res;
}

    
int matrix(int n,int k,int v[][100])
{
  int i,j;

  for(i=0;i<100;i++)
    {
      for(j=0;j<100;j++)
	{
	  mat[i][j]=0;
	}
    }
  
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  if(v[i][j]!=0)
	    mat[i][v[i][j]-1]=1;	 
	}
      
    }
  /* for(i=0;i<n;i++)
     {
     for(j=0;j<n;j++)
     {	 
     // printf("%d",mat[i][j]);
     if(j!=n-1)
     {
     printf(" ");
     }
     }
     printf("\n");
     }
  */  
}
  

int next(int y)
{
  int s,i;
  for(i=0;i<n;i++)
    {      
      if(mat[y-1][i]==1)
	{	  
	  s=i;
	  mat[y-1][s]=0;
	  return i+1;
	}
      
    }
  return null;

}

int istop()
{
  return stack[top];
}

void dfs()
{
  int i;
  for(i=1;i<=n;i++)
    {     
      color[i]=WHITE;     
    }
  timer=0;
  for(i=1;i<=n;i++)
    {
      if(color[i]==WHITE)
	visit(i);
    }
}

void visit(int r)
{
  int u,v;
  
  push(r);
  color[r]=GRAY;
  d[r]=++timer;
  while(top!=0)
    {
      u=istop();
      v=next(u);
      if(v!=null)
	{
	  if(color[v]==WHITE)
	    {
	      push(v);
	      color[v]=GRAY;
	      d[v]=++timer;
	    }
	}
      else
	{
	  pop();
	  color[u]=BLACK;
	  f[u]=++timer;
        }
     
    }
  
}
  

