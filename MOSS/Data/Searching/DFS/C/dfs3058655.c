#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<stdbool.h>
#define ms(l,n,s) memset(l,n,s)
#define m(l,n) (l*)malloc(n*sizeof(l))
#define lpton(i,n) for(int i=0;i<(int)n;i++)
#define lpto0(i,n) for(int i=n;i>-1;i--)
#define lpmn(i,m,n) for(int i=m;i<n;i++)
void dfs(int**,int*,int*,int,int);
void print(int*,int*,int);
int ord=1;
int main(){
  int n,u,k,v;
  int **matrix;
  int *dis,*fin;
  scanf("%d",&n);
  matrix=m(int*,(n+1));
  dis=m(int,(n+1));
  fin=m(int,(n+1));
  ms(dis,0,((n+1)*sizeof(int)));
  ms(fin,0,((n+1)*sizeof(int)));
  *(dis+1)=ord;
  ord++;
  lpton(i,(n+1)){
    *(matrix+i)=m(int,(n+1));
    ms(*(matrix+i),0,((n+1)*sizeof(int)));
  }
  lpton(i,n){
    scanf("%d%d",&u,&k);
    lpton(j,k){
      scanf("%d",&v);
      *(*(matrix+u)+v)=1;
    }
}
  dfs(matrix,dis,fin,1,n);
  lpmn(i,1,(n+1))if(!*(dis+i)){
    *(dis+i)=ord++;
    dfs(matrix,dis,fin,i,n);
  }
  print(dis,fin,n);
  return 0;
}
void print(int *dis,int *fin,int n){
  lpmn(i,1,(n+1))printf("%d %d %d\n",i,*(dis+i),*(fin+i));
}
void dfs(int **mtx,int *dis,int *fin,int i,int n){
// if(ord>(n*2))return;
    lpmn(j,1,(n+1)){
      if(*(*(mtx+i)+j)){
        if(!*(dis+j)){
      *(dis+j)=ord++;
      dfs(mtx,dis,fin,j,n);
      }
    }
  }
  *(fin+i)=ord++;
}

