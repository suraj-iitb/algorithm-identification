#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define P pair<int,int>
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define FORR(I,A,B) for(int I = ((B)-1); I >= (A); --I)
#define TO(x,t,f) ((x)?(t):(f))
#define SORT(x) (sort(x.begin(),x.end())) // 0 2 2 3 4 5 8 9
#define REV(x) (reverse(x.begin(),x.end())) //reverse
int gcd(int a,int b){if(a<b)swap(a,b);if(a%b==0)return b;return gcd(b,a%b);}
int lcm(int a,int b){int c=gcd(a,b);return ((a/c)*(b/c)*c);}//saisyo kobaisu
#define NEXTP(x) next_permutation(x.begin(),x.end())
const ll INF=1e18+7;
const ll MOD=1e9+7;
#define pri(a) cout << (a) << endl

int ans = 0;
void merge(int A[],int left,int mid,int right){
	int n1 = mid - left;
	int n2 = right - mid;
	int L[n1+1],R[n2+1];
	for(int i=0;i<n1;i++){
		L[i] = A[left+i];
	}
	for(int i=0;i<n2;i++){
		R[i] = A[mid+i];
	}
	L[n1] = R[n2] = 1000000000;
	int i = 0;
	int j = 0;
	for(int k=left;k<right;k++){
		ans++;
		if(L[i]<=R[j]){
			A[k] = L[i];
			i++;
		}else{
			A[k] = R[j];
			j++;
		}
	}
}
void mergeSort(int A[],int left,int right){
	if(left+1<right){
		int mid = ( left + right )/2;
		mergeSort(A,left,mid);
		mergeSort(A,mid,right);
		merge(A,left,mid,right);
	}
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	FOR(i,0,n)cin>>a[i];
	mergeSort(a,0,n);
	cout << a[0];
	FOR(i,1,n)cout << " " << a[i];
	cout << endl << ans << endl; 
}

