#include<stdio.h>

#define MAX 101
#define WHITE 0
#define GRAY 1
#define BLACK 2

int C[MAX],A[MAX][MAX],d[MAX],f[MAX],time=0,k[MAX];

void visit(int);
 
 int main()
 {
   int n,i,j,v,id;

   scanf("%d",&n);

   for(i = 1 ; i <= n ; i ++)
     {
       scanf("%d",&id);
       scanf("%d",&k[id]);
       for(j = 1 ; j <= k[id] ; j++)
	 {
	   scanf("%d",&v);
	   A[id][j] = v;
	 }
     }

   for(i = 1 ; i <= n ; i++)
     {
       C[i] = WHITE;	 
     }

   for(i = 1 ; i <= n ; i++)
     {
       if(C[i] == WHITE) visit(i);
     }

   for(i = 1 ; i <= n ; i++)
     {
       printf("%d %d %d\n",i,d[i],f[i]);
     }
   
   return 0;
 }

void visit(int u)
{
  int v,i;
  
  C[u] = GRAY;
  d[u] = ++time;

  for(i = 1 ; i <= k[u] ; i++)
    {
      v = A[u][i];
      if(C[v] == WHITE) visit(v);
    }

  C[u] = BLACK;
  f[u] = ++time;

  return;
}

