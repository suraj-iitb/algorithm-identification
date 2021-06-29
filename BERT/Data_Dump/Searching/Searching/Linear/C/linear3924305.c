#include<stdio.h>


int main(void){
	int n,q;
	int i;
	scanf("%d",&n);
	int S[n];
	for(i=0;i<n;i++){			//S入力
		scanf("%d",&S[i]);
		}
	scanf("%d",&q);
	int T[q];
	for(i=0;i<q;i++){			//T入力
		scanf("%d",&T[i]);
	}
	int count=0;
	
	for(i=0;i<n;i++){			//同一要素削除
		for(int j=i+1;j<n;j++){
			if(S[i]==S[j])S[j]=-1;
		}
	}
		
	
	for(i=0;i<n;i++){
		for(int j=0;j<q;j++){
			if(S[i]==T[j])count++;
		}
	}
	printf("%d\n",count);
	return 0;
}
		
