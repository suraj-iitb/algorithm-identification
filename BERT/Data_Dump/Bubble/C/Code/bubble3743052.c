#include<stdio.h>
#include <stdlib.h>
#define ll long long
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}

ll a[110];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%lld",a+i);
	int ans=0;
	for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)ans+=a[i]>a[j];
	sortup(a,n);
	for(int i=0;i<n;i++)printf("%d%c",a[i],i==n-1?10:32);
	printf("%d\n",ans);
}
