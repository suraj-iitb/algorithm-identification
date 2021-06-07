#include<stdio.h>

int time;
int n;

void visit(int i,int a[n][n],int b[n][3]);

int main(void)
{
	scanf("%d",&n);
	
	int i,j;
	
	int a[n][n];
	int b[n][3];
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			a[i][j] = 0;
		}
	}
	
	for(i=0;i<n;i++){
		for(j=0;j<3;j++){
			b[i][j] = 0;
		}
	}
	
	int u,k,v;
	
	for(i=0;i<n;i++){
		scanf("%d %d",&u,&k);
		
		for(j=0;j<k;j++){
			scanf("%d",&v);
			
			a[u-1][v-1] =1;
		}
	}
	
	time=0;
	
	for(i=0;i<n;i++){
		if(b[i][0] == 0){
			visit(i,a,b);
		}
	}
	
	for(i=0;i<n;i++){
		printf("%d %d %d\n",i+1, b[i][1], b[i][2]);
	}
	
	return 0;
}

void visit(int i,int a[n][n],int b[n][3])
{
	b[i][0]++;
	time++;
	b[i][1] = time;
	
	int j;
	
	for(j=0;j<n;j++){
		if(a[i][j] != 0){
			if(b[j][0] == 0){
				visit(j,a,b);
			}
		}
	}
	
	b[i][0]++;
	time++;
	b[i][2] = time;
}
