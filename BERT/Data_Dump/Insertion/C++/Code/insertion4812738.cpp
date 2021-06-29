#include <iostream>
using namespace std;
int main(){
	int n,i,j,x,v;
	cin >> n;
	int a[n];
	for(i=0;i<n;i++){
		cin >> a[i];
		cout << a[i];
		if(i!=n-1) cout << ' ';
	}
	cout << endl;
	for(i=1;i<n;i++){
		v = a[i];
		j = i-1;
		while(j>=0&&a[j]>v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1]=v;
		for(x=0;x<n;x++){
			cout << a[x];
			if(x!=n-1) cout << ' ';
		}
		cout << endl;
	}
	return 0;
	
}
