#include <stdio.h>
int m[100][100];
int d[100];
int n;
int t;
int Q[1000];
int head,tail;


void enqueue(int n){
  Q[tail] = n;
  tail = (tail+1)%1000;
}
int dequeue(){
  int n;
  n = Q[head];
  head = (head+1)%1000;
  return n;
}



int main (){
  int i,j,k,u,r;

  scanf("%d",&n);
  for(i=0;i<n;i++){
    d[i] = -1;
    for(j=0;j<n;j++){
      m[i][j] = 0;
    }
  }

  for(i=0;i<n;i++){
    scanf("%d",&r);
    scanf("%d",&k);
    for(j=0;j<k;j++){
      scanf("%d",&u);
      m[r-1][u-1] = 1;
    }
  }

  d[0] = 0;
  head = 0;
  tail = 0;
  enqueue(0);

  while(head != tail){
    u = dequeue();
    for(i=0;i<n;i++){
      if(m[u][i] && d[i] == -1){
	d[i] = d[u]+1;
	enqueue(i);
      }
    }
  }


  for(i=0;i<n;i++){
    printf("%d %d\n",i+1,d[i]);
  }
  return 0;
}
