#include<stdio.h>
#define N 101
int sum[N][N],tum[N],a;

void num(int xu){
	int Q[100000],fan,zin, i;
	fan=zin=0;

	Q[zin]=xu;	
	++zin;


	while(fan!=zin){
	
		xu=Q[fan];
		++fan;
		for(i=1;i<=a;i++){
			if(sum[xu][i]){
				if(tum[i]>=0)continue;

			
				Q[zin]=i;	++zin;
				tum[i]=tum[xu]+1;
			}
		}
	}
}

int main(){
	int i,j,u,k,v;

	scanf("%d",&a);
	for(i=0;i<a;i++){
		scanf("%d%d",&u,&k);
		tum[u]=-1;
		for(j=0;j<k;j++){
			scanf("%d",&v);
			sum[u][v]=1;
		}
	}
	tum[1]=0;

    num(1);
	for(i=1;i<=a;i++){
		printf("%d %d\n",i,tum[i]);
	}

	return 0;
}

