#include <bits/stdc++.h>

using namespace std;  
const int maxn = 100000;
int n;
struct card{
	char name; int val;
};
card s[maxn+4],s1[maxn+4];
card L[maxn+4],R[maxn+4];
int partition(int p,int r){
	int x = s[r].val;
	int i = p-1;
	for(int j=p;j<r;j++){
		if(s[j].val <= x){
			i++;swap(s[i],s[j]);
		}
	}
	swap(s[i+1],s[r]);
	return i+1;
}
void quicksort(int p,int r){
	if(p < r){
		int q = partition(p,r);
		quicksort(p,q-1);
		quicksort(q+1,r);
	}
}
void merge(int left,int mid,int right){
	int n1 = mid -left;
	int n2 = right - mid;
	for(int i=0;i<n1;i++) L[i] = s1[left+i];
	for(int i=0;i<n2;i++) R[i] = s1[mid+i];
	L[n1].val = INT_MAX;R[n2].val = INT_MAX;
	int i=0;int j=0;
	for(int k=left;k<right;k++){
		if(L[i].val <= R[j].val) s1[k] = L[i++];
		else s1[k] = R[j++];
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
void alds_1_6_c(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) cin>>s[i].name>>s[i].val;
	memcpy(s1,s,sizeof(s));
	quicksort(0,n-1);
	mergesort(0,n);
	bool flag = true;
	for(int i=0;i<n;i++){
		if(s[i].name != s1[i].name) {flag = false;break;}
	}
	if(flag) printf("Stable\n");
	else printf("Not stable\n");
	for(int i=0;i<n;i++){
		if(i>0) printf("\n");
		printf("%c %d",s[i].name,s[i].val);
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
	alds_1_6_c();
	//printf("Time used = %.5f ms\n", (double)clock() / CLOCKS_PER_SEC *1000);
	return 0;
}
