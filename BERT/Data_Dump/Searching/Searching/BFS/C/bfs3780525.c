#include <stdio.h>
#define MAX 105
#define INF 2e8

int G[MAX][MAX], d[MAX], n, head = 0, tail = 0, Q[MAX];

int isEmpty(){
	return head == tail;	
}

int isFull(){
	return head == (tail +1) % MAX;
}

void enqueue(int x){
	if (isFull())
		printf("overflow");
	Q[tail] = x;
	if ((tail+1)==MAX)
		tail = 0;
	else
		tail++;
}
int dequeue(){
	int x;
	if (isEmpty())
		printf("underflow");
	x = Q[head];
	Q[head] = -1;
	if ((head+1) == MAX)
		head = 0;
	else
		head++;
	return x;
}


int main(void) {
  int u,k,v,i,j,id;
 
  scanf("%d",&n);
  for(i=0; i<n; i++){
  	d[i]=INF;
  	Q[i]=-1;
	for(j=0; j<n ;j++)
  		G[i][j] = 0;
  }

  for(i=0; i<n; i++){
	scanf("%d%d",&u,&k);
	for(j=0; j<k; j++){
  		scanf("%d",&v);
  		G[u-1][v-1] = 1;
	}
  }
   
  d[0]=0;
  enqueue(0);
  while(!isEmpty()){
  	id = dequeue();
  	for(i=0; i<n; i++){
  		if(G[id][i] == 0)
  			continue;
  		if(d[id] + 1 < d[i]){
  			d[i] = d[id] + 1;
  			enqueue(i);
  		}
  	}
  }
  for(i=0;i<n;i++){
	if(d[i]==-1 || d[i]==200000000)
		printf("%d -1\n", i+1);
	else printf("%d %d\n", i+1, d[i]);
  }
  

  return 0;
}
