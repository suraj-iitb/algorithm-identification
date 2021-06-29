#include <stdio.h>
#define N 100
#define A 0
#define B 3
#define C 5

int n,unchi[N][N];
int pri[N],fi[N],judge[N],count;

void DEPTH(int );
void depth(void);

void DEPTH (int st){
  int a;
  judge[st]=1;
  pri[st]= ++count;

  for(a=0;a<n;a++){
    if(unchi[st][a]==0)
      continue;
    if(judge[a]==0){
      DEPTH(a);
    }
  }

  judge[st]=2;
  fi[st]=++count;
}
  
void depth(){
  int b;

  for(b=0;b<n;b++)
    judge[b]=0;
  count=0;

  for(b=0;b<n;b++){
    if(judge[b]==0)
      DEPTH(b);
  }

  for(b=0;b<n;b++){
    printf("%d %d %d\n",b+1,pri[b],fi[b]);
  }
}

int main(){
  int i,j,k,s,t;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++)
      unchi[i][j]=0;
  }

  for(i=0;i<n;i++){
    scanf("%d%d",&s,&k);
    s--;

    for(j=0;j<k;j++){
      scanf("%d",&t);
      t--;
      unchi[s][t]=1;
    }
  }

  depth();

  return 0;
}

