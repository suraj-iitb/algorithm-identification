#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cstdlib>
using namespace std;
 
int main () {
	int n,i,j,v,k;
	cin >> n;
	int a[n];
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	for(k=0;k<n;k++){
		if(k==n-1) cout << a[k];
		else cout << a[k] << " ";
	}
	cout << endl;
	for(i=1;i<=n-1;i++){
		v=a[i];
		j=i-1;
		while((j>=0)&&(a[j]>v)){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=v;
		for(k=0;k<n;k++){
			if(k==n-1) cout << a[k];
			else cout << a[k] << " ";
		}
		cout << endl;
	}
}
