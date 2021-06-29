#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int a[110];

int main(){
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i = 1 ; i<=n ; i++){
		cin>>a[i];
	}
	
	int ans = 0;
	for(int i = 1 ; i<=n ; i++){
		for(int j = 1 ; j<=n-i ; j++){
			if(a[j] > a[j+1]){
				swap(a[j],a[j+1]);
				ans++;
			}
		}
	}
	
	for(int i = 1 ; i<=n ; i++){
		if(i == 1)
			cout<<a[i];
		else{
			cout<<" "<<a[i];
		}
	}
	cout<<endl;
	cout<<ans<<endl;
	return 0;
}

