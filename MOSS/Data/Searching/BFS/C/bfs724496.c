#include<stdio.h>

int main(){

  int n;

  scanf("%d", &n);


  int g[102][102],d[102];


  int i,j;
  for(i=1;i<=n;i++){
    for(j=1;j<=n;j++){
      g[i][j] = 0;
    }
    d[i]=-1;
  }

  int u,k;
  for(i=0;i<n;i++){
    scanf("%d %d", &u,&k);
    for(j=0;j<k;j++){
      int v;
      scanf("%d", &v);
      g[u][v] = 1;
    }
  }

  int Q[102];
  int head=0,tail;
  tail=head+1;

    Q[head]=1;
    //  tail+=1;
    d[Q[head]]=0;
    while(head!=tail){
      u=Q[head];
      head++;
      for(i=1;i<=n;i++){
	if(g[u][i]==1 && d[i]==-1){
	  g[u][i]=0;
	  d[i]=d[u]+1;
	  Q[tail++]=i;
	    }
	}
    }


  for(i=1;i<=n;i++){
    printf("%d %d\n", i, d[i]);
  }
  return 0;
}
