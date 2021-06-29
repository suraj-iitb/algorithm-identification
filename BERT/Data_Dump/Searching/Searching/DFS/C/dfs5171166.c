#include<stdio.h>
#define WHITE -1
#define BLACK -2
#define GRAY -3
int pop(void);
void push(int);
void visit(int);
void DFS(void);
int next(int);

int n;
int Stack[101];
int color[101];
int d[101];
int f[101];
int data[101][101];
int top = 0;
int time;
int main()
{
  int i,j,k,choten,tonari;

  scanf("%d",&n);

  for(i=0;i<=n;i++){
    for(j=0;j<=n;j++){
      data[i][j] = 1000000001;
    }
  }
  for(i=1;i<=n;i++){
    scanf("%d%d",&choten,&k);
    for(j=0;j<k;j++){
              scanf("%d",&tonari);
      data[choten][tonari] = tonari;
    }
  }
  DFS();

  for(i=1;i<=n;i++)
    {
      printf("%d %d %d\n",i,d[i],f[i]);
    }

  return 0;
}

int pop(void)
{
  if(top == 0){
    return 0;
  }

  top--;
  return Stack[top+1];
}

void push(int num)
{
  if(top == 100) printf("スタックがいっぱいです！\n");

  Stack[top+1] = num;
  top++;
}

void visit(int r)
{
  int result,u,v;
  result = 1;
  push(r);
  color[r] = GRAY;
  d[r] = time;
  while(result != 0){
    u = Stack[top];
    v = next(u);
    if(v < 1000000001) {
      if(color[v] == WHITE){
        push(v);
        color[v] = GRAY;
        d[v] = ++time;
        data[u][v] = 1000000001;
      }
    }
        else{
      result = pop();
      color[u] = BLACK;
      f[u] = ++time;
    }
  }
}
int next(int a)
{
  int i,result;
  result = 1000000002;
  for(i=1;i<=n;i++){
    if(result > data[a][i]){
      if(color[i] == WHITE){
        result = data[a][i];
      }
    }
  }

  return result;
}

void DFS(void)
{
  int i;
  for(i=1;i<=n;i++) color[i] = WHITE;
  time = 1;
  for(i=1;i<=n;i++){
    if(color[i] == WHITE) visit(i);
  }
}

