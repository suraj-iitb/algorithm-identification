#include <stdio.h>

int linerSearch(int n,int *s,int k){
	int i;
	for(i = 0;i < n;i ++){
		if(s[i] == k)return 1;
	}
	return 0;
}
int main(void){
	int n,i,s[10000];
	int cnt = 0;
	scanf("%d",&n);
	for(i = 0;i < n;i++ ){
		scanf("%d",&s[i]);
	}
	int p,t;
	scanf("%d",&p);
	for(i = 0; i < p; i++){
		scanf("%d",&t);
		cnt += linerSearch(n,s,t);
	}
	
	printf("%d\n",cnt);
	return 0;
}
