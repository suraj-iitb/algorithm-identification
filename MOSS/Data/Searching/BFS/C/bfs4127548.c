#include <stdio.h>

#define GRAY 0
#define WHITE 1
#define BLACK -1

typedef struct{
  int color;
  int cnt;
  int next[10];
}Node;

int d[101];
Node dfs[101];

int head,tail,que[101];

void enqueue(int x){
  que[tail]=x;
  tail = (tail+1)%101;
}

int dequeue(void){
  int x;
  x=que[head];
   head = (head+1)%101;
  return x;
}



int main(){

  int n,m,k,l,i,j,u;
  
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    dfs[i].color=WHITE;
    d[i]=1000000000;
    scanf("%d%d",&m,&k);
    for(j=1;j<=k;j++){
      scanf("%d",&l);
      dfs[i].next[j]=l;
      dfs[i].cnt=k;
      // printf("aaa %d\n",dfs[i].next[j]);
    }
    
  }
  
  dfs[1].color=GRAY;
  d[1]=0;
  enqueue(1);

  while(head!=tail){
 
    u=dequeue();
    for(i=1;i<=dfs[u].cnt;i++){
      //  printf("coooo %d\n",dfs[dfs[u].next[i]].color);
      // printf("%d next %d color:%d\n",u,dfs[u].next[i],dfs[dfs[u].next[i]].color);
      if(dfs[dfs[u].next[i]].color==WHITE){
	dfs[dfs[u].next[i]].color=GRAY;
	d[dfs[u].next[i]]=d[u]+1;
	enqueue(dfs[u].next[i]);
	//	printf("now:%d distance:%d next:%d\n",u,d[u],dfs[u].next[i]);
      }
    }
    dfs[u].color=BLACK;
    // printf("\n");
  }
  for(i=1;i<=n;i++) {
    if(d[i]==1000000000)d[i]=-1;

    printf("%d %d\n",i,d[i]);


  }

  
 
return 0;
}

