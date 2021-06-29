#include <bits/stdc++.h>

using namespace std;  
const int maxd = 100;
int R[maxd+4];

void alds_1_2_a(){
	int n;scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&R[i]);
	bool flag = true;
	int cnt = 0;
	while(flag){
		flag = false;
		for(int j=n-1;j>0;j--){
			if(R[j] < R[j-1]) {swap(R[j],R[j-1]); flag = true;cnt++;}
		}
	}
	for(int i=0;i<n;i++){if(i>0) printf(" ");printf("%d",R[i]);}
	printf("\n%d\n",cnt);
}
//#define LOCAL
int main(int argc, char** argv) {
	#ifdef LOCAL
		FILE *fin,*fout;
		fin = freopen("in.txt","r",stdin);
		fout = freopen("out.txt","w",stdout);
	#endif
	alds_1_2_a();
	//printf("Time used = %.9f\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}
