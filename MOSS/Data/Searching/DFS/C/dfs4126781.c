#include<stdio.h>
#define MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

void deep(void);
void deepsearch(int);
int n,A[MAX][MAX],s[MAX],e[MAX],c[MAX],time;

int main()
{
int i,j,x,y,z;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)
      A[i][j]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&x,&y);
    for(j=0;j<y;j++)
      {scanf("%d",&z);
	A[x-1][z-1]=1;}
  }
deep();

return 0;  
}

void deep()
{
 int i;
 for(i=0;i<n;i++)
   {c[i]=WHITE;
    time=0;    }
for(i=0;i<n;i++){
if(c[i]==WHITE)deepsearch(i);}
for(i=0;i<n;i++)
  printf("%d %d %d\n",i+1,s[i],e[i]);
}

void deepsearch(int x)
{int i;
c[x]=GRAY;
s[x]=++time;
for(i=0;i<n;i++){
if(A[x][i]==0)continue;
if(c[i]==WHITE)deepsearch(i);
  }
c[x]=BLACK;
e[x]=++time;
}

