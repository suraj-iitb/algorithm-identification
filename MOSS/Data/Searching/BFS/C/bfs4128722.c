#include <stdio.h>

#define black 1
#define white 0
#define gray 2
#define INF -1

void bfs(void);
int dequeue(void);
void enqueue(int);

int num;
int a[110][110];
int di[110];
int color[110];
int data[110];
int total;
int head;

int main(){
  int i,j;
  int elem,in,sum;

  scanf("%d",&num);
  for(i=1;i<=num;i++){
    for(j=1;j<=num;j++) a[i][j]=white; 
  }

  for(i=1;i<=num;i++){
    scanf("%d%d",&elem,&sum);
    for(j=1;j<=sum;j++){
      scanf("%d",&in);
      a[elem][in]=black;
    }
  }
  bfs();
  for(i=1;i<=num;i++) printf("%d %d\n",i,di[i]);
  
  return 0;
}

void bfs(void){
  int i,j,l;
  int k;
  
  for(i=1;i<=num;i++){
      color[i]=white;
      di[i]=INF;
  }
  color[1]=gray;
  di[1]=0;
  enqueue(1);
  
  while(head!=num){
    k=dequeue();
    for(j=1;j<=num;j++){
      if(a[k][j]==black){
	if(color[j]==white){
	  color[j]=gray;
	  di[j]=di[k]+1;
	  enqueue(j);
	}
      }
    }
    color[k]=black;
  }
}

void enqueue(int k){
  data[++total]=k;
}

int dequeue(void){
  return data[++head];
}

