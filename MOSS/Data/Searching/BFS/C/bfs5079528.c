#include<stdio.h>

#define N 101

int glaph[N][N];
int minpath[N];
int def[N];
int n;


void shortpathSarch(int k){ 
	
	int s;
	
	for(s=0;s<n;s++){
		if(glaph[k][s]==1){     //経路があり
			if(minpath[k]==-1){
				minpath[s]=1;
			}
			else if(minpath[k]!=0){
				if(minpath[s]!=0&&minpath[k]+1>=minpath[s]){
					//最小経路が更新されていて今の方が小さい時何もしない。
				}
				else{
					if(s!=0)minpath[s]=minpath[k]+1;
				}
			}
		}
	}

}

int main(void){
	
	int i,j,k,u,v;
	
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			glaph[i][j]=0;
		}
		minpath[i]=0;
	}
	
	for(i=0;i<n;i++){
		scanf("%d %d",&u,&k);
		for(j=0;j<k;j++){
			scanf("%d",&v);
			glaph[u-1][v-1]=1;
		}	
	}
	
	minpath[0]=-1;
	
	for(i=0;i<n;i++){
		shortpathSarch(i);
	}
	for(i=0;i<n;i++){
		shortpathSarch(i);
	}
	
	for(i=0;i<n;i++){
		
		if(i==0){
			printf("%d %d\n",i+1,minpath[i]+1);
		}
		else if(minpath[i]==0){
			printf("%d %d\n",i+1,minpath[i]-1);
		}
		else{
			printf("%d %d\n",i+1,minpath[i]);
		}
	}
	
	return 0;
}
