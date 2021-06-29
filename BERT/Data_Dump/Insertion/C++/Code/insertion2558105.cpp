#include<bits/stdc++.h>
using namespace std;
const int MAXN=110;
int n,a[MAXN];
void output(int a[],int n){
	int i;
	for(i=0;i<n;i++){
		if(i>0) printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
}
int main() {
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	int v,j,i;
	output(a,n);
	for(i=1; i<n; i++) {
		v=a[i];
		j=i-1;
		while(j>=0&&a[j]>v) {
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		output(a,n);
	}
}
