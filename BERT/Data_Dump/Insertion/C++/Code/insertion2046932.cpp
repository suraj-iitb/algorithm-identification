#include<iostream>
#include<utility>

using namespace std;

int main(){
	int i, j, n, *a, tmp;
	cin >> n;
	a = new int[n];
	for(i = 0; i < n; i++){
		cin >> a[i];
	}
	for(i = 0; i < n; i++){
		tmp = i;
		for(j = 0; j < i; j++){
			if(a[i] < a[j]){
				for(int k = i - 1; k >= j; k--){
					swap(a[tmp], a[k]);
					tmp--;
				}
			}
		}
		for(j = 0; j < n; j++){
			if(j != n - 1) cout << a[j] << " ";
			else cout << a[j] << endl;
		}
	}

	return 0;
}
