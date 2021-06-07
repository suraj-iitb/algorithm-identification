#include<stdio.h>
#define N 101
int n,m[N][N],s[N],d[N],f[N],cntd=1,cntf=0,count=0;

int pop(int top){
  if(top==0)return -1;
  return top-1;
}
int push(int num,int top){
  top++;
  s[top]=num;
  return top;
}

int dfs(int num){
  int i,j,top=1;
  if(count!=0)d[num]=++cntd;
  d[1]=1;
  s[top]=num;
  for(i=1;i<=n;i++)m[i][num]=0;
  while(top!=0){
     for(i=1;i<=n;i++){
          if(m[s[top]][i]==1){
              for(j=1;j<=n;j++)m[j][i]=0;
              top=push(i,top);
              cntd++;
              if(d[i]==0)d[i]=cntd;
              break;
          }
          else if(i==n){
            cntf=++cntd;
            f[s[top]]=cntf;
            top=pop(top);
           }      
        }
        
  }
  for(i=2;i<=n;i++){
    if(d[i]==0){
      count++;
      return dfs(i);
  }
  }
            
  return 0;

}

int main(){
  int i,j,num,k,num1;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    scanf("%d%d",&num,&k);
    for(j=1;j<=n;j++)m[i][j]=0;
    for(j=1;j<=k;j++){
      scanf("%d",&num1);
      m[i][num1]=1;
    }
  }
  for(i=1;i<=n;i++){
    d[i]=0;
    f[i]=0;
  }
  k=dfs(1);
for(i=1;i<=n;i++){
      printf("%d %d %d\n",i,d[i],f[i]);
  }
  return 0;
}


