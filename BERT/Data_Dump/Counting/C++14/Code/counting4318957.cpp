#include<iostream>
#include<algorithm>
using namespace std;
#define maxi 2000001
int n;
void counting(int a[],int b[],int k){
int i,j,c[10001];
	for(i=0;i<=k;i++)
	c[i]=0;
	for(j=1;j<=n;j++)
	c[a[j]]++;
	for(i=1;i<=k;i++)
	c[i]=c[i]+c[i-1];
	for(j=n;j>0;j--){
	b[c[a[j]]]=a[j];
		c[a[j]]--;
	}
}

main(){
	int i,a[maxi],b[maxi],ma;
	ma=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
	scanf("%d",&a[i]);
		ma=max(ma,a[i]);
	}
	counting(a,b,ma);
	for(i=1;i<=n;i++){
		if(i==n)
		printf("%d\n",b[i]);
		else
		printf("%d ",b[i]);
	}
	return 0;
}

