

#include <stdio.h>
#include <stdlib.h>
int count=0;
void visit(int u, int *jude, int *d, int *f, int size);
int d[101], f[101],jude[101];
int matrix[101][101];
int main(int argc, char** argv) {
    int size;
    int degree;

    scanf("%d", &size);
    
    
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
        scanf("%d %d",&temp, &degree);
        for(int j=0;j<degree;j++)
        {
            scanf("%d", &a);
            matrix[temp-1][a-1]=1;
        }
    }
    for(int i=0;i<size;i++)
    {
        if(jude[i]==0)
            visit(i,jude,d,f, size);
    }
    
    for(int i=0;i<size;i++)
    {
        printf("%d %d %d\n", i+1, d[i], f[i]);
    }
  
    return (EXIT_SUCCESS);
}


void visit(int u, int *jude, int *d, int *f, int size)
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
}

