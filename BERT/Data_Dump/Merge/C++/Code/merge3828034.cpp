#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
// #define psortsecond(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.second<b.second;});
// #define psortfirst(A,N) sort(A,A+N,[](const pii &a, const pii &b){return a.first<b.first;});
#define All(x) (x).begin(),(x).end()
using namespace std;
// using pii  = pair<int,int>;
long long gcd(long long a, long long b){return (b == 0 ? a : gcd(b, a%b));}
long long lcm(long long a, long long b){return a*b/gcd(a,b);}
int BinarySearch(int key,int n,int S[]){
	int l=0,r=n;
	while(r-l>1){
		int mid=(l+r)/2;
		if(S[mid]>key)r=mid;
		else l=mid;
	}
	return S[l]==key?1:0;
}
typedef long long ll;
#define MOD 1000000007
#define EPS 10e-8

const int INF=10e9+11; 
int cnt;

void merge(int *A,int left,int mid,int right){
  int n1=mid-left;
  int n2=right-mid;
  int L[n1+1],R[n2+1];
  for(int i=0;i<n1;i++) L[i]=A[left+i];
  for(int i=0;i<n2;i++) R[i]=A[mid +i];
  L[n1]=INF;
  R[n2]=INF;
  int i=0,j=0;
  for(int k=left;k<right;k++){
    cnt++;
    if(L[i]<=R[j]) A[k]=L[i++];
    else A[k]=R[j++];
  }
}
void mergeSort(int *A,int left,int right){
  if(left+1<right){
    int mid=(left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}
signed main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  int n;
  cin>>n;
  int S[n];
  for(int i=0;i<n;i++) cin>>S[i];
  cnt=0;
  mergeSort(S,0,n);
  for(int i=0;i<n;i++) cout<<S[i]<<" \n"[i==n-1];
  cout<<cnt<<endl;
  return 0;
}
