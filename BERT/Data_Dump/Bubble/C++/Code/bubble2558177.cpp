#include<bits/stdc++.h>
using namespace std;
const int MAXN=110;
int n;
int a[MAXN];
int main() {
	int n,cnt=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	bool flag=1;
	for(int i=0; flag; i++) {
		flag=0;
		for(int j=n-1; j>=i+1; j--) {
			if(a[j]<a[j-1]) {
				swap(a[j],a[j-1]);
				flag=1;
				cnt++;
			}
		}
	}
	for(int i=0; i<n; i++) {
		if(i) cout<<" ";
		printf("%d",a[i]);
	}
	printf("\n");
	printf("%d\n",cnt);
}
