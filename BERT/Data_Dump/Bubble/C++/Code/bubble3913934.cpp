#include<iostream>
using namespace std;
const int MAXN=105;
int A[MAXN];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>A[i];
	int res=0;
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			if(A[j]<A[j-1]){
				swap(A[j],A[j-1]);
				res++;
			}
		}
	}
	for(int i=0;i<n;i++){
		cout<<A[i];
		if(i!=n-1)cout<<" ";
	}
	cout<<endl;
	cout<<res<<endl;
	return 0;
}

