//compiledef
#include <bits/stdc++.h>
#define rep(i, n) for(i=0;i<(n);i++)
#define per(i, n) for(i=(n);i>0;i--)
#define repx(i, n, x) for(i=(x);i<(n);i++)
#define xper(i, n, x) for(i=(n);i>(x);i--)
#define pback push_back

//c++def
using namespace std;
typedef long long int ll;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
int cnt;
void merge(int *a, int left, int mid, int right){
	int i;
	int j;
	int k;
	int n1=mid-left;
	int n2=right-mid;
	vector<int> L;
	vector<int> R;
	rep(i, n1) L.pback(a[left+i]);
	rep(i, n2) R.pback(a[mid+i]);
	L[n1] = 2e9;
	R[n2] = 2e9;
	for(i=0, j=0, k=left;k<right;k++){
		if(L[i]<=R[j]){
			a[k] = L[i];
			i++;
			cnt++;
		}else{
			a[k] = R[j];
			j++;
			cnt++;
		}
	}
}

void mergesort(int *a, int left, int right){
	if(left+1<right){
		int mid = (left+right)/2;
		mergesort(a, left, mid); //bunkatsu(recursion)
		mergesort(a, mid, right);
		merge(a, left, mid, right);
	}
}

int main(){
	int i;
	int n;
	int a[500001];
	cin >> n;
	rep(i, n) scanf("%d",&a[i]);
	mergesort(a, 0, n);
	rep(i, n){
		if(i !=0)printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	cout << cnt << endl;
}



