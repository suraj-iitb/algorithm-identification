#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define N 101
#define NOT_find 0
#define find 1
#define finish -1

void dfs(void);
void visit(void);
int Emptycheck(void);
void push(int);
int pop(void);
int Stop(void);
int isEmpty(void);
int isFull(void);
int nmin(int);

int n;
int stop;
int check[N];
int S[N];
int Ssize=0;
int fstamp[N];
int sstamp[N];
int v[N][N];

int main(){

  int i,j,k,id;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    check[i]=NOT_find;
    fstamp[i]=0;
    sstamp[i]=0;
    for(j=1;j<=n;j++){
      v[i][j]=INT_MAX;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d",&id);//input id

    scanf("%d",&k);

    for(j=1;j<=k;j++){
      scanf("%d",&v[id][j]);
    }
  }

  visit();

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,fstamp[i],sstamp[i]);
  }


  return 0;
} 
 
int nmin(int id){

  int j,min,k;

  min=INT_MAX;
  for(j=1;j<=n;j++){
    if(min>=v[id][j]){
      min=v[id][j];
      k=j;
  }
}
  v[id][k]=INT_MAX;
  return min;
}

void visit(void){

  int t=0,V,u,i;

  for(i=1;i<=n;i++){
    if(check[i]==NOT_find){
    push(i);
    check[i]=find;
    ++t;
    fstamp[i]=t;
    }
    while(Emptycheck()){
      u=Stop();
      V=nmin(u);
      if(V==INT_MAX)V=0;
      if(V!=0){
        if(check[V]==NOT_find){
          push(V);
          check[V]=find;
          ++t;
          fstamp[V]=t;
        }
      }
            else{
        u=pop();
        check[u]=finish;
        ++t;
        sstamp[u]=t;
      }
    }
  }
}

int Emptycheck (void){

  if(Ssize!=0)return 1;
  else return 0;
}

void push(int x){

  if(isFull()==1){
    printf("Stack overflow!\n");
    exit(2);
  }

  S[Ssize] = x;
  Ssize++;
}

int Stop(void){
  return S[Ssize-1];
}

int pop(void){
  if(isEmpty() == 1){
    exit(3);
  }
  Ssize--;
  return S[Ssize];

}

int isEmpty(void){
  if(Ssize == 0)return 1;
  else return 0;
}

int isFull(void){
  if(Ssize == N)return 1;
  else return 0;
}
