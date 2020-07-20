#include<bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main(){
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i){
		cin>>a[i];
	}


	int cnt=0;
	bool flag = true;
	while(flag){
		flag=false;
		for (int i = n-1; i > 0 ; --i){
			if(a[i]<a[i-1]){
				swap(a[i],a[i-1]);
				cnt++;
				flag=true;
			}
		}
	}

	for (int i = 0; i < n; ++i){
		if(i!=n-1){
			cout<<a[i]<<" ";
		}else{
			cout<<a[i]<<endl;
			cout<<cnt<<endl;
		}
	}

	return 0;
}

