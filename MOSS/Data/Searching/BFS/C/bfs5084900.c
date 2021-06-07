#include<stdio.h>

#define N 101

int a[N][N],x[N],y[N];

int main(void){
	int n,i,j,b,c,d,head=0,tail=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d",&b,&c);
		for(j=0;j<c;j++){
			scanf("%d",&d);
			a[b][d]=1;
		}
	}
	for(i=1;i<n+1;i++)x[i]=-1;
	y[tail++]=1;
	x[1]=0;
	while(head!=tail){
		int w;
		w=y[head++];
		for(i=1;i<=n;i++){
			if(x[i]==-1&&a[w][i]==1){
				x[i]=x[w]+1;
				y[tail++]=i;
			}
		}
	}
	for(i=1;i<=n;i++)printf("%d %d\n",i,x[i]);
	return 0;
}
