#include <iostream>
using namespace std;

int main(){
	int v,n,a[100] = {},i,j;
	cin >> n;
	for(i = 0;i < n;i++){
		cin >> a[i];
	}
		for(int k = 0;k < n;k++){
		if(k != n-1){
			cout << a[k] << " ";
		}
		else cout << a[k] << endl;
		}

	for(i = 1;i < n;i++){
		v = a[i];
		j = i - 1;
		while(j >= 0 && a[j] > v){
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = v;

		for(int k = 0;k < n;k++){
		if(k != n-1){
			cout << a[k] << " ";
		}
		else cout << a[k] << endl;
		}
	}
	return 0;
}
