#include <stdio.h>

int search(int a[],int t,int low,int high);

int main(void) {

	int ans,n,q,low,high,t,i,j;
	int a[100000]= {-1};

	ans=0;

	scanf("%d",&n);

	for(i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}

	scanf("%d",&q);

	low=0;
	high=n-1;

	for(j=0; j<q; j++) {
		scanf("%d",&t);

		ans+=search(a,t,low,high);

	}

	printf("%d\n",ans);

	return 0;
}

int search(int a[],int t,int low,int high) {
	int mid=(low+high)/2;

	if(t==a[mid]) {
		return 1;
	}
	else if(high<low) {
		return 0;
	}
	else if(t>a[mid]) {
		return search(a,t,mid+1,high);
	}
	else {
		return search(a,t,low,mid-1);
	}
}

