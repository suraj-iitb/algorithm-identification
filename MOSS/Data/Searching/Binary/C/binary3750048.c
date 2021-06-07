#include <stdio.h>

int n;
int a[100010];
int bs(int k){
	if(a[0]>k)return 0;
	int l=0,r=n;
	while(r-l>1){
		int m=(l+r)/2;
		if(a[m]<=k)l=m;
		else r=m;
	}
	return a[l]==k;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	int q;
	scanf("%d",&q);
	int ans=0;
	while(q--){
		int t;
		scanf("%d",&t);
		ans+=bs(t);
	}
	printf("%d\n",ans);
}
