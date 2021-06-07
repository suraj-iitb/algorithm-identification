#include <stdio.h>

#define black 1
#define white 0
#define gray 2

void dfs(void);
void visit(int);

int fi[110];
int di[110];
int color[110];
int time;
int num;
int a[110][110];

int main(){
  int sum,elem,in;
  int i,j;

  scanf("%d",&num);

  for(i=1;i<=num;i++){
    for(j=1;j<=num;j++) a[i][j]=white;
  }
  
  for(i=1;i<=num;i++){
    scanf("%d%d",&elem,&sum);

    if(sum==0) continue;

    for(j=1;j<=sum;j++){
      scanf("%d",&in);
      a[elem][in]=black;
    }
  }
  
  dfs();

  for(i=1;i<=num;i++){
    printf("%d %d %d\n",i,di[i],fi[i]);
  }
  
  return 0;
}

void dfs(void){
  int i;
  for(i=1;i<=num;i++) color[i]=white;//syokika
  time=0;
  
  for(i=1;i<=num;i++){//black ni narumade
    if(color[i]==white) {
      visit(i);
    }
  }
}

void visit(int k){
  int i;
  color[k]=gray;//tootta
  di[k]=++time;
  
  for(i=1;i<=num;i++){
    if(a[k][i]==black){//tooreru
      if(color[i]==white) visit(i);//mada tootteinai
    }
  }
  
  color[k]=black;
  fi[k]=++time;
  
}


