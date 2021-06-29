#include <bits/stdc++.h>

using namespace std;  
const int maxn = 500000;
int s[maxn+4];
int L[maxn],R[maxn];
int n,cnt;
void merge(int left,int mid,int right){
	int n1 = mid - left;
	int n2 = right - mid;
	for(int i=0;i<n1;i++) L[i] = s[left+i];
	for(int i=0;i<n2;i++) R[i] = s[mid+i];
	L[n1] = INT_MAX;R[n2] = INT_MAX;
	int i=0;int j=0;
	for(int k=left;k<right;k++){
		cnt++;
		if(L[i] <= R[j]) s[k] = L[i++];
		else s[k] = R[j++];
	}
}
void mergesort(int left,int right){
	if(left + 1 < right){
		int mid = (left + right) >> 1;
		mergesort(left,mid);
		mergesort(mid,right);
		merge(left,mid,right);
	}
}
void alds_1_5_b(){
	cnt = 0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&s[i]);
	mergesort(0,n);
	for(int i=0;i<n;i++){
		if(i > 0) printf(" ");
		printf("%d",s[i]);
	}
	printf("\n%d\n",cnt);
}

//#define LOCAL
int main(int argc, char** argv) {
	#ifdef LOCAL
		FILE *fin,*fout;
		fin = freopen("in.txt","r",stdin);
		fout = freopen("out.txt","w",stdout);
	#endif
	alds_1_5_b();
	//printf("Time used = %.5f ms\n", (double)clock() / CLOCKS_PER_SEC *1000);
	return 0;
}
