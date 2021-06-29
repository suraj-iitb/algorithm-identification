#include<stdio.h>
#include<string.h>
#define N 1000
#define W 0
#define X 0
#define Y 1
#define Z 2

int n,head,tail,M[N][N];
int d[N],c[N],Q[N];

void enqueue(int x){
	Q[tail] = x;
	tail++;
}

int dequeue(){
	head++;
	return Q[head];
}

void depth(int u){
	int i,j,s;
	
	
	for(i=0;i<N;i++){
		c[i] = X;
		d[i] = W;
	}
	
	c[u] = Y;
	d[u] = 0;
	
	enqueue(u);
	
	while(head+1!=tail){
		s = dequeue();
		for(j=0;j<n;j++){
			if(M[s][j]==0){
				continue;
			}
			if(c[j]==X){
				c[j] = Y;
				d[j] = d[s] + 1;
				enqueue(j);
			
			}
		}
		c[s] = Z;
	}
	for(i=1;i<n;i++){
		if(d[i]==W){
			d[i] = -1;
		}
	}
}



int main(void){
	int u,k,v,i,j;
	
	scanf("%d",&n);
	
	head = 0;
	tail = n+1;
		
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			M[i][j] = 0;
		}
	}
	
	for(i=0;i<n;i++){
		scanf("%d %d",&u,&k);

		for(j=0;j<k;j++){
			scanf("%d",&v);
			M[u-1][v-1]=1;
		}
	}
	

	depth(0);

	for(i=0;i<n;i++){
		printf("%d %d\n",i+1,d[i]);
	}
	
	
	return 0;
}

