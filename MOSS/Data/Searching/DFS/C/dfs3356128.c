#include<stdio.h>
#define MAX 100

int n,t=0,math[MAX][MAX],ans1[MAX],ans2[MAX],tmp[MAX];
//DFS
void calc(int u){
  int i;
  tmp[u]=1;
  ans1[u]= ++t;
  for(i=0;i<n;i++) if(math[u][i]==1 &&tmp[i]==0)calc(i);
  tmp[u]=2;
  ans2[u]= ++t;
}

void set(int num){
    int i,j;
    for(i=0;i<num;i++){
        tmp[i]=0;
        for(j=0;j<num;j++)math[i][j]=0;
    } 
}

void input(int num){
    int i,j,v,k,w;
    for(i=0;i<num;i++){
        scanf("%d%d",&v,&k);
        for(j=0;j<k;j++){
          scanf("%d",&w);
          math[v-1][w-1]=1;
        }
    }
}

int main(){
  int i;
  
  scanf("%d",&n);
  
  set(n);
 
  input(n);
  //calc
  for(i=0;i<n;i++) if(tmp[i]==0) calc(i);
  //output
  for(i=0;i<n;i++) printf("%d %d %d\n",i+1,ans1[i],ans2[i]);
  
  return 0;
}
