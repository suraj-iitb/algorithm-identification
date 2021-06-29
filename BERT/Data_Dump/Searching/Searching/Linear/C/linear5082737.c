#include <stdio.h>

int linerS(int key, int S[], int n){
	int count=0;
	S[n] = key;
	while(S[count]!=key) count++;
	return count != n;
	}

int main(){
	int n,q,S[10000],key,i,ans=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&S[i]);
		}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&key);
		if(linerS (key, S, n)) ans++;
	}
	printf("%d\n",ans);
	return 0;
}
