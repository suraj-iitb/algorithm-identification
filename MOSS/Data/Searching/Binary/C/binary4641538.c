#include<stdio.h>
int n, q, S[100100], T, ans=0;
int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", S+i);
	}
	scanf("%d", &q);
	while(q--){
		scanf("%d", &T);
		int l=-1, r=n;
		while(r-l > 1){
			int mid = (l+r)/2;
			if(S[mid]<T)l=mid;
			else r=mid;
		}
		if(T == S[r])ans++;
	}
	printf("%d\n", ans);
	return 0;
}

