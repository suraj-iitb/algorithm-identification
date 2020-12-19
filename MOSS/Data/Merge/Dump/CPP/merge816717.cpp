#include<map>
#include<set>
#include<list>
#include<cmath>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<vector>
#include<complex>
#include<cstdlib>
#include<cstring>
#include<numeric>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<functional>
#include<limits>;

#define mp       make_pair
#define pb       push_back
#define all(x)   (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,b,n) for(int i=b;i<n;i++)

using namespace std;

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    vector<bool>       vb;
typedef    vector<int>        vi;
typedef    vector<vb>         vvb;
typedef    vector<vi>         vvi;
typedef    pair<int,int>      pii;

const ll INF=1<<30;
const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
ll A[500010];
ll cnt = 0;
void merge(ll *A,int left,int mid,int right){
	int n1 = mid-left;
	int n2 =right -mid;
	ll L[n1+1];
	ll R[n2+1];
	for(int i = 0;i <n1;i++){
		L[i] = A[left+i];
	}
	for(int i = 0;i < n2;i++){
		R[i] =A[mid+i];
	}
	L[n1]=INF;
	R[n2]=INF;
	int i = 0;
	int j = 0;
	for(int k = left;k <=right-1;k++){
		if(L[i]<=R[j]){
			A[k] =L[i];
			i++;
			cnt++;
		}else{
			A[k] = R[j];
			j++;
			cnt++;
		}
	}
}
void merge_sort(ll *A,int left,int right){
	if(left+1<right){
		int mid = (left+right)/2;
		merge_sort(A,left,mid);
		merge_sort(A,mid,right);
		merge(A,left,mid,right);
	}
}
int main(){
	int n;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>A[i];
	}
	int left = 0;
	int right = n;
	merge_sort(A,left,right);
	for(int i = 0;i < n;i++){
		cout <<A[i];
		if(i!=n-1){
			cout <<" ";
		}else{
			cout <<endl;
		}
	}
	cout <<cnt<<endl;
	return 0;
}
