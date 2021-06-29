#include <bits/stdc++.h>

using namespace std;  
const int maxd = 100;
int R[maxd+4];

void alds_1_1_a(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&R[i]);
	for(int i=0;i<n-1;i++) printf("%d ",R[i]);
	printf("%d\n",R[n-1]);
	for(int i=1;i<n;i++){
		int v = R[i];
		int j = i-1;
		while(j>=0 && R[j] > v){
			R[j+1] = R[j];
			j--;
		}
		R[j+1] = v;
		for(int k=0;k<n-1;k++) printf("%d ",R[k]);
		printf("%d\n",R[n-1]);
	}
}
//#define LOCAL
int main(int argc, char** argv) {
	#ifdef LOCAL
		FILE *fin,*fout;
		fin = freopen("in.txt","r",stdin);
		fout = freopen("out.txt","w",stdout);
	#endif
	alds_1_1_a();
	//printf("Time used = %.9f\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}
