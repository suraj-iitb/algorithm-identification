#include<stdio.h>

#define N 101

#define A 0
#define B 1
#define C 2

void Depth_First_Search(void);
void visit(int);
int next(int);
void push(int);
void pop(void);

int ori[N][N];
int judgement[N],fir[N],sec[N],tc,numord[N];
int n,S[N],top=-1;

int main()
{
  int i,j,a,b,c;

  for(i=1;i<= N;i++){
    for(j=1;j<=N;j++){
      ori[i][j]=0;
    }
  }

  scanf("%d",&n);

  for(i = 1; i <= n; i++){
    scanf("%d %d",&a,&b);
    for(j = 1; j <= b; j++){
      scanf("%d",&c);
      ori[a][c] = 1;
    }
  }

  Depth_First_Search();

  return 0;
}

void Depth_First_Search()
{
  int i;
  for(i=1;i<=n;i++){
    judgement[i] = A;
  }

  for(i=1;i<=n;i++){
    if(judgement[i]==A) visit(i);
  }

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,fir[i],sec[i]);
  }
}

void visit(int i)
{
  int numtop,x;

  push(i);
  judgement[i]=B;
  tc++;
  fir[i]=tc;

  while(top!=-1){
    numtop=S[top];
    x=next(numtop);

    if(x!=-1){
      if(judgement[x]==A){
	       judgement[x]=B;
         tc++;
	       fir[x]=tc;
	        push(x);
        }
      }

    else {
      pop();
      judgement[numtop]=C;
      tc++;
      sec[numtop]=tc;
    }
  }
}

int next(int t)
{
  int i;

  for(i=numord[t]+1;i<=n;i++){
    numord[t]=i;
    if(ori[t][i]) return i;
  }
  return -1;
}

void push(int x)
{
  top++;
  S[top]=x;
}

void pop()
{
  top--;
}

