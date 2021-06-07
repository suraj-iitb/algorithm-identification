#include<stdio.h>
#include<stdlib.h>
int main(void){
	int n;
	scanf("%d",&n);
	int i,S[n];
	for(i=0; i<n; i++){
		scanf("%d",&S[i]);
	}
	int q;
	scanf("%d",&q);
	int j,T[q];
	for(j=0; j<q; j++){
		scanf("%d",&T[j]);
	}
	int cnt=0;
	int same[n];
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(S[i]==S[j]){
				same[j]=1;
			}
		}
	}
	for(i=0; i<n; i++){
		if(same[i]!=1){
			for(j=0; j<q; j++){
				if(S[i]==T[j]){
					cnt++;
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}
