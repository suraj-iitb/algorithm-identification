#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int ll;

int main()
{
    int n,a[100];
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i];
		
	}
	for(int i=1;i<=n;i++){
	  sort(a,a+i);
		for(int j=0;j<n;j++){
			if(j==n-1)cout << a[j] << "\n";
			else cout << a[j] << " ";
		}
	}
    return 0;
}
