#include <bits/stdc++.h>

using namespace std;  
const int maxn = 2000000;
int n;
int a[maxn+4],b[maxn+4],c[maxn+4];
void count_sort(int k){
	for(int i=0;i<=k;i++) c[i] = 0;
	for(int j=1;j<=n;j++) c[a[j]]++;
	for(int i=1;i<=k;i++) c[i] = c[i] + c[i-1];
	for(int j=n;j>0;j--) {
		b[c[a[j]]] = a[j];
		c[a[j]]--;
	}
}
void alds_1_6_a(){
	scanf("%d",&n);
	int maxv = 0;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		maxv = max(maxv,a[i]);
	}
	//cout<<maxv<<endl;
	count_sort(maxv);
	for(int i=1;i<=n;i++){
		if(i>1) printf(" ");
		printf("%d",b[i]);
	}
	printf("\n");
}

//#define LOCAL
int main(int argc, char** argv) {
	#ifdef LOCAL
		FILE *fin,*fout;
		fin = freopen("in.txt","r",stdin);
		fout = freopen("out.txt","w",stdout);
	#endif
	alds_1_6_a();
	//printf("Time used = %.5f ms\n", (double)clock() / CLOCKS_PER_SEC *1000);
	return 0;
}
