#include<iostream>
using namespace std;
int main(){
	int n,time=0;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++){
		int min=i;
		bool flag=false;
		for(int j=i;j<n;j++){
			if(a[j]<a[min]){
				min=j;
				flag=true;
			}
		}
		if(flag){
			swap(a[i],a[min]);
			time++;
		}
		//for(int k=0;k<n;k++) cout << a[k] << ' ';
		//cout << "\n";
	}
	for(int k=0;k<n;k++){
		cout << a[k];
		if(k!=n-1) cout << ' ';
	}
	cout << '\n' << time << '\n';
	return 0;
}
