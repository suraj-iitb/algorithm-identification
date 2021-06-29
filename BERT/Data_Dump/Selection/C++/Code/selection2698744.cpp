#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
	int dum = a;
	a = b;
	b = dum;
	return;
}

int main(){
	int n, t, minj;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i != n; i++) cin >> a[i];

	t = 0;
	for (int i = 0; i != n; i++){
		minj = i;
		for (int j = i; j != n; j++){
			if (a[j] < a[minj]){
				minj = j;
			}
		}
		if (minj != i){
			swap(a[i], a[minj]);
			t++;
		}
	}

	for (int i = 0; i != n; i++) cout << (i == 0 ? "" : " ") << a[i];
	cout << endl << t << endl;
}
