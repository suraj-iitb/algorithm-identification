#include <stdio.h>

typedef struct {
  int time[2];
  int flag;
} Data;

int n,v[200][200];
Data data[200];

int aaa(int num, int time){
  int i;
  data[num].flag = 1;
  data[num].time[0] = time;
  for(i=1;i<=n;i++){
    if(v[num][i]==1 && data[i].flag==0){
      time = aaa(i,time+1);
    }
  }
  data[num].time[1]=time+1;
  return time+1;
}

int main(){
  int i,j,m,t,time=0;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      v[i][j]=0;
      data[i].flag=0;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d%d",&t,&m);
    for(j=0;j<m;j++){
      scanf("%d",&t);
      v[i][t]=1;
    }
  }

  for(i=1;i<=n;i++){
    if(data[i].flag==0){
      time = aaa(i,time+1);
    }
  }

  for(i=1;i<=n;i++){
    printf("%d %d %d\n",i,data[i].time[0],data[i].time[1]);
  }

  return 0;
}

