#include<stdio.h>

int main(){

	int n;
	scanf("%d",&n);
	int S[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);	
	}
	
	int q;
	scanf("%d",&q);
	int T[q];
	for(i=0;i<q;i++){
		scanf("%d",&T[i]);	
	}
	
	int C=0;
	int key=0;
	int k;
	for(i=0;i<q;i++){
		key=T[i];
		for(k=0;k<n;k++){
			if(key==S[k]){
			C++;
			break;
			}
		}
	}
	
	
	printf("%d\n",C);
	return 0;
}
