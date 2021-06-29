#include<stdio.h>

int Search(int *,int,int);
int main(){
	int i,n,a[100000],q,t,sum=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&q);
	for(i=0;i<q;i++){
		scanf("%d",&t);
		sum+=Search(a,n,t);
	}
	printf("%d\n",sum);
	return 0;
}

int Search(int *a,int n,int t){
	int mid,F,L;
	F=0;
	L=n;
	while(F<L){
		mid=(F+L)/2;
		if(a[mid]==t)return 1;
		else if(a[mid]>t){
			L=mid;
		}else F=mid+1;
	}
	return 0;
}
