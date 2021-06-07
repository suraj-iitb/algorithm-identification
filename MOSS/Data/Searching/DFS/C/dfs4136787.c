#include<stdio.h>
#define N 102

#define siro 0
#define hai 1
#define kuro 2

int ha[N],owa[N];
int o;
int time;
int iro[N];
int M[N][N];
void S(int);
int main(){
  int i,j,k,n,M2;
  
  scanf("%d",&o);
  
  for(i=1;i<=o;i++){
    for(j=1;j<=o;j++){
      M[i][j]=0;
    }
  }
  for(i=1;i<=o;i++){
    scanf("%d%d",&n,&k);
    for(j=1;j<=k;j++){ 
      scanf("%d",&M2);
      M[n][M2]=1;
    }
  }
  for(i=1;i<=o;i++){
    iro[i]=siro;
  }
  for(i=1;i<=o;i++){
    if(iro[i]==siro){
      S(i);
    }
  }
  for(i=1;i<=o;i++){
    printf("%d %d %d\n",i,ha[i],owa[i]);
  }
  return 0;
}
void S(int s){
  int j;
  iro[s]=hai;
  
  ha[s]=++time;
  
  for(j=1;j<=o;j++){ 
    if (M[s][j]==0) continue;
    if(iro[j]==siro)S(j);
  }
   owa[s]=++time;
  iro[s]=kuro;
 
}

