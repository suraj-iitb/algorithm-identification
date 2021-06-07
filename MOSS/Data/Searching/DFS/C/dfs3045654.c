#include<stdio.h>
#include<stdlib.h>
typedef struct Graph
{
  int key;
  int numOfAdj;
  int *adj;
  int status;//0:not discovered, 1:discovered, 2:finished
} graph;
void depthFirstSearch(void);
void visit(int);
int n;//num of vertice
graph *p;//array of vertice
int *d;//timestamp of first discovered time
int *f;//timestamp of finishing examining time
int timeOfSearch;//time passed during the depth first search
int main(void)
{
  int i,j;//counter
  int key,numOfAdj,adj;
  scanf("%d",&n);
  p=(graph*)malloc(sizeof(graph)*n);
  d=(int*)malloc(sizeof(int)*n);
  f=(int*)malloc(sizeof(int)*n);
  for(i=0;i<n;i++)
    {
      scanf("%d",&key);
      scanf("%d",&numOfAdj);
      p[key-1].numOfAdj=numOfAdj;
      p[key-1].adj=(int*)malloc(sizeof(int)*numOfAdj);
      for(j=0;j<numOfAdj;j++)
	{
	  scanf("%d",&adj);
	  p[key-1].adj[j]=adj-1;
	}
      p[key-1].status=0;
      d[i]=0;
      f[i]=0;
    }
  depthFirstSearch();
  return 0;
}
void depthFirstSearch(void)
{
  int i;//counter
  timeOfSearch=0;
  for(;;)
    {
      for(i=0;i<n;i++)
	{
	  if(p[i].status==0) visit(i);
	}
      if(i==n) break;
    }
  for(i=0;i<n;i++)
    {
      printf("%d %d %d\n",i+1,d[i],f[i]);
    }
}
void visit(int key)
{
  int i;//counter
  p[key].status=1;
  timeOfSearch++;
  d[key]=timeOfSearch;
  for(i=0;i<p[key].numOfAdj;i++)
    {
      if(p[p[key].adj[i]].status==0) visit(p[key].adj[i]);
    }
  p[key].status=2;
  timeOfSearch++;
  f[key]=timeOfSearch;
}


