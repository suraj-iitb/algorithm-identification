#include<stdio.h>
#define N 101

int n,A[N][N],a[N],e[N];

void ser(int b,int t){
	int i;
	e[b]=t;
	for(i=0;i<a[b];i++){
		if(t+1 < e[A[b][i]-1]){
			ser(A[b][i]-1,t+1);
		}
	}
}

int main(void)
{
	int i,j,c;
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			A[i][j]=0;
		}
	}
	
	for(i=0;i<n;i++){
		e[i]=7000;
		scanf("%d",&c);
		scanf("%d",&a[c-1]);
		for(j=0;j<a[c-1];j++){
			scanf("%d",&A[c-1][j]);
		}
	}
	ser(0,0);
	for(i=0;i<n;i++){
		if(e[i]==7000){
			printf("%d %d\n",i+1,-1);
		}
		else{
			printf("%d %d\n",i+1,e[i]);
		}
	}
	return 0;
}
	
	


