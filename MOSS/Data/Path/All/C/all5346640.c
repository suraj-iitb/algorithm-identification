#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c;
int mpp[105][105];

int main(){
	scanf("%d %d",&n,&m);
	
	for(int i=0;i<105;i++)for(int j=0;j<105;j++)mpp[i][j]=2147483647;
	for(int i=0;i<=n;i++)mpp[i][i]=0;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&a,&b,&c);
		mpp[a][b]=c;
	}
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			if(mpp[i][k]!=2147483647)
			for(int j=0;j<n;j++){
				if(mpp[k][j]!=2147483647)
				mpp[i][j]=min(mpp[i][j],mpp[i][k]+mpp[k][j]);
			}
		}
	} 
	for(int i=0;i<n;i++){
		if(mpp[i][i]<0){
			printf("NEGATIVE CYCLE\n");
			return 0;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(j!=0)printf(" ");
			if(mpp[i][j]==mpp[104][104])printf("INF");
			else printf("%d",mpp[i][j]);
		}
		printf("\n");
	}
} 
