#include <stdio.h>
#include <stdlib.h>
typedef struct{
  int cell;
  int befcell;
  int atime;
  int btime;
  int frag;
}node;
int main(){
  int i,j,n,m,sel,k,time=0,a=0;
  int **Adj;
  node *V;
  scanf("%d",&n);
  V = malloc(n*sizeof(node));
  Adj = malloc(n*sizeof(int *));
  for(i=0;i<n;i++)
    {
      Adj[i] = malloc(n*sizeof(int));
      V[i].cell = i+1;
      V[i].atime = 0;
      V[i].btime = 0;
      V[i].frag = 0;
    }
  for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
	{
	  Adj[i][j] = 0;
	}
    }
  for(j=0;j<n;j++)
    {
      scanf("%d%d",&sel,&m);
      for(i=0;i<m;i++)
	{
	  scanf("%d",&k);
	  Adj[sel-1][k-1]++;
	}
    }

  V[a].befcell = -1;
  for(i=0;i<n;i++)
    {
      if(i==0 && V[a].frag ==0)
	{
	  time++;
	  V[a].atime=time;
	}
      if(Adj[a][i]>=1 && V[i].frag == 0)
	{
	  
	  V[a].frag = 1;
	  V[i].befcell=a;
	  a=i;
	  i=-1;	  
	  continue;
	}
      if(i==n-1)
	{
	  time++;
	  V[a].btime=time;
	  if(V[a].befcell == -1) break;
	  V[a].frag = 1;
	  a=V[a].befcell;
	  i=-1;
	  
	}
    }
  for(j=0;j<n;j++)
    {
      if(V[j].frag == 0)
	{
	  
	  a=j;
	  V[a].befcell = -1;
	  for(i=0;i<n;i++)
	    {
	      if(i==0 && V[a].frag ==0)
		{
		  time++;
		  V[a].atime=time;
		}
	      if(Adj[a][i]>=1 && V[i].frag == 0)
		{
		  V[a].frag = 1;
		  if(i != a){
		    V[i].befcell=a;}
		  a=i;
		  i=-1;	  
		  continue;
		}
	      if(i==n-1)
		{
		  time++;
		  V[a].btime=time;
		  if(V[a].befcell == -1) break;
		  V[a].frag = 1;
		  a=V[a].befcell;
		  i=-1;
	  
		}
	    }
	}
    }
  
  
  for(i=0;i<n;i++)
    printf("%d %d %d\n",V[i].cell,V[i].atime,V[i].btime);
  
  return 0;
}

