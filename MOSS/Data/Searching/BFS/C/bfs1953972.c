#include<stdio.h>
#define N 200


int g[N][N],d[N];
int color[N],k[N],Q[N];
int time,num;
int head=0,tail=0;


int de(int Q[]){
  head++;
  return Q[head-1];
}
void en(int Q[],int s){
  Q[tail]=s;
  tail++;
}


void B_F_S(int s){
  int i,u;

  for(i = 1;i <= num; i++){
    color[i] = 0;
    d[i] = -1;
  }
  color[s]=1;
  d[s]=0;
  en(Q,s);

  while(head!=tail){
    u=de(Q);
    for(i=1;i<=num;i++){
      if(g[u][i]==1){
        if(color[i]==0){
          color[i]=1;
          d[i]=d[u]+1;
          en(Q,i);
        }
      }
    }
    color[u]=2;
  }
}

int main(){
  int i,j,l;
  int u,v;

  scanf("%d",&num);

  for(i = 0;i < num; i++){
    scanf("%d",&u);
    scanf("%d",&l);
    for(j = 0;j < l;j++){
      scanf("%d",&v);
      g[u][v] = 1;
    }
  }


  B_F_S(1);
  for(i = 1; i <=num;i++){
    printf("%d %d\n", i,d[i]);
  }
  return 0;
}
