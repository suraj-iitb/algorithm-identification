#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define N 100

int main(){
	int n,ans=0,minj;
	int a[N];
	cin >> n;
	for(int i=0;i<n;i++){
		int k;
		cin >> k;
		a[i]=k;
	}	
	for(int i=0;i<n;i++){
		minj = i;
		for(int j=i;j<n;j++){
			if(a[j]<a[minj]){
				minj = j;
			}
		}
		if(minj!=i){
			int k = a[i];
			a[i] = a[minj];
			a[minj] = k;
			ans++;
		}
	}
	for(int i=0;i<n;i++){
		cout << a[i];
		if(i != n-1){
			cout << " ";
		}
	}
	cout << endl << ans << endl;
	return 0;
}
