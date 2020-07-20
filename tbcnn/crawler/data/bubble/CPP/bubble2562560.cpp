#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define N 100

int main(){
	int n,ans=0;
	int a[N];

	cin >> n;
	for(int i=0;i<n;i++){
		int k;
		cin >> k;
		a[i]=k;
	}	
	int flag = 1;
	while(flag){
		flag = 0;
		for(int j=n-1;j>0;j--){
			if(a[j] < a[j-1]){
				int w = a[j];
				a[j] = a[j-1];
				a[j-1] = w;
				ans++;
				flag = 1;
			}
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
