#include <stdio.h>

typedef struct {
  int time;
  int flag;
} Data;

int n,v[200][200];
int q[200],head=0,b=1,tail=1;
Data data[200];

void eq(int x){
  q[tail]=x;
  tail++;
}

int dq(void){
  head++;
  return q[head-1];
}

int main(){
  int i,j,m,t,time=1;

  scanf("%d",&n);

  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      v[i][j]=0;
      data[i].flag=0;
      data[i].time=-1;
    }
  }

  for(i=1;i<=n;i++){
    scanf("%d%d",&t,&m);
    for(j=0;j<m;j++){
      scanf("%d",&t);
      v[i][t]=1;
    }
  }

  q[0]=1;
  data[1].time=0;
  data[1].flag=1;

  while(1){
    //printf("b\n");
    for(i=head;i<b;i++){
      t=dq();
      for(j=1;j<=n;j++){
	if(v[t][j]==1 && data[j].flag==0){
	  eq(j);
	  data[j].time=time;
	  data[j].flag=1;
	}
      }
    }
    time++;
    head=b;
    b=tail;
    if(head==b)break;
    //printf("%d %d %d\n",head,b,tail);
  }

  for(i=1;i<=n;i++){
    printf("%d %d\n",i,data[i].time);
  }

  return 0;
}

