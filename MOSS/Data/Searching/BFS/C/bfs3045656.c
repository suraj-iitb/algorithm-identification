#include<stdio.h>
#include<stdlib.h>
typedef struct Graph
{
  int key;
  int numOfAdj;
  int *adj;
  int status;//0:not discovered, 1:discovered, 2:finished
} graph;
int n;//num of vertice
graph *p;//array of vertice
int *d;//array of degree
int *queue;
int head=0,tail=0;
void breadthFirstSearch(int);
void enqueue(int);
int dequeue(void);
int main(void)
{
  int i,j;//counter
  int key,numOfAdj,adj;
  scanf("%d",&n);
  p=(graph*)malloc(sizeof(graph)*n);
  d=(int*)malloc(sizeof(int)*n);
  queue=(int*)malloc(sizeof(int)*n);
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
      d[i]=-1;
    }
  breadthFirstSearch(0);
  return 0;
}
void breadthFirstSearch(int start)
{
  int i;//counter
  int u,v;
  d[start]=0;
  enqueue(start);
  while(head!=tail)
    {
      u=dequeue();
      for(i=0;i<p[u].numOfAdj;i++)
	{
	  v=p[u].adj[i];
	  if(p[v].status==0)
	    {
	      p[v].status=1;
	      d[v]=d[u]+1;
	      enqueue(v);
	    }
	}
      p[u].status=2;
    }
  for(i=0;i<n;i++)
    {
      printf("%d %d\n",i+1,d[i]);
    }
}
void enqueue(int key)
{
  queue[tail]=key;
  tail++;
}
int dequeue(void)
{
  head++;
  return queue[head-1];
}

