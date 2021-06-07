#include<stdio.h>

#define N 100

int glaph[N][N];
int d[N],f[N],save[N];
int n,count=0;

void depthsarch(int k){ 	//0を未探索、-1を探索中、-2を探索済みとする。
							//ノードがつながっている限り(forおわってから再帰して最後に-2
	int i;
	
	save[k]=-1;				//探索中にする
	d[k]=++count; 			//探索開始時刻を記録
	
	for(i=0;i<n;i++){       	//行き先があり、未探索であるノードを次の探索
		if(glaph[k][i]==1){ 
			if(save[i]==0){ 	
				depthsarch(i);
			}
		}
	}

	f[k]=++count; 			//探索完了時刻を記録
	save[k]=-2;			//探索済みにする
}


int main(void){
	
	int i,j,k,u,v;
	
	
	scanf("%d",&n);
	
	for(i=0;i<n;i++){   //まとめて初期化
		save[i]=0;
		f[i]=0;
		d[i]=0;
		for(j=0;j<n;j++){
			glaph[i][j]=0;
		}
	}
	
	for(i=0;i<n;i++){
		scanf("%d %d",&u,&k);
		for(j=0;j<k;j++){
			scanf("%d",&v);
			glaph[u-1][v-1]=1;
		}	
	}
	
	
	
	for(i=0;i<n;i++){  //未探索ノードがあれば
		if(save[i]==0){ 
			depthsarch(i);
		}
	}
	
	
	for(i=0;i<n;i++){
		printf("%d %d %d\n",i+1,d[i],f[i]);
	}
		
	
	return 0;
}
