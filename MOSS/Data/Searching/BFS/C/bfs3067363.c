

#include <stdio.h>
#include <stdlib.h>
int count=0;
int dequeue(void);
void enqueue(int);
void visit(int u, int *jude, int *d, int *f, int size);
int d[101], f[101],jude[101], Q[101];
int matrix[101][101];
int head=0,tail = 0;
int max(int size,int *degree);
int main(int argc, char** argv) {
    int size;
    scanf("%d", &size);
    int degree[size];
    for(int i=0;i<size;i++)
    {
        jude[i]=0; 
        for(int j=0;j<size;j++)
        {
            matrix[i][j]=0;
        }
    }
    
    
    int temp, a;
    for(int i=0;i<size;i++)
    {
        scanf("%d %d",&temp, &degree[i]);
        for(int j=0;j<degree[i];j++)
        {
            scanf("%d", &a);
            matrix[temp-1][a-1]=1;
        }
    }
    for(int i=0;i<size;i++)
    {
        if(matrix[0][i]==1)
            jude[i]=0;
    }
    jude[0]=1;
    int distant[size];
    distant[0]=0;
    enqueue(0);
    
    int tempu;
    while(head!=tail)
    {
        tempu=dequeue();
        for(int i=0;i<size;i++){
        if(matrix[tempu][i]==1 && jude[i]==0){
	jude[i]=1;
	distant[i]=distant[tempu]+1;
	enqueue(i);
      }
      jude[tempu]=2;
    }
  }
    
    /*for(int i=0;i<size;i++)
    {
        if(jude[i]==0)
            visit(i,jude,d,f, size);
    }*/
    
    
    for(int i=0;i<size;i++)
    {
        if(jude[i]==2)
            printf("%d %d\n", i+1, distant[i]);
        else
            printf("%d -1\n", i+1);
    }
  
    return (EXIT_SUCCESS);
}

/*void visit(int u, int *jude, int *d, int *f, int size)
{
  int i;
  jude[u]=1;
  d[u]=++count;
  for(i=0;i<size;i++){
    if(matrix[u][i]==1)
    {
      if(jude[i]==0)
          visit(i, jude, d, f, size);
    }
  }
  jude[u]=2;
  f[u]=++count;
}*/

int max(int size,int *degree)
{
    int max=0;
    for(int i=0;i<size;i++)
    {
        if(degree[i] > max)
            max = degree[i];
    }
    return max;
}
int dequeue()
{
  int x;
  x=Q[head];
  if(head+1==100)head=0;
  else head=head+1;
  return x;
}

void enqueue(int x)
{
  Q[tail]=x;
  if(tail+1==100)tail=0;
  else tail=tail+1;
}
