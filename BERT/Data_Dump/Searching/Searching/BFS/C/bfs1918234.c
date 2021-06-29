#include<stdio.h>

#define N 101
#define WHITE 0
#define GRAY 1
#define BRACK 2

void bfc(int);
void enqueue(int);
int dequeue(void);

int n,M[N][N],p[N],head,tail,color[N];
int d[N];

int main(){
	int i,j,v,k,u;

	scanf("%d",&n);
	for(i = 0;i < n;i++){
		for(j = 0;j < n;j++){
			M[i][j] = 0;
		}
	}

	for(i = 0;i < n;i++){
		scanf("%d%d",&u,&k);
		u--;
		for(j = 0;j < k;j++){
			scanf("%d",&v);
			v--;
			M[u][v] = 1;
		}
	}

bfc(0);

for(i = 0;i < n;i++){
printf("%d %d\n",i+1,d[i]);
}


return 0;
}

void bfc(int s){
 int i,j;
  for(i = 0;i < n;i++){
    color[i] = WHITE;
    d[i] = -1;
  }
  color[s] = GRAY;
  d[s] = 0;
  enqueue(s);
  while(head != tail){
    i = dequeue();
    for(j = 0;j < n;j++){
      if(color[j] == WHITE && M[i][j] == 1){
        color[j] = GRAY;
        d[j] = d[i] + 1;
        enqueue(j);
      }
    }
    color[i] = BRACK;
  }
}




void enqueue(int x){
p[tail] = x;
tail++;
}

int dequeue(void){
	int x;
	x = p[head];
	head++;
	return x;  
}
