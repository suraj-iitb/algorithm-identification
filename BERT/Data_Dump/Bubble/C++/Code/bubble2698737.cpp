#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n, t, dum, unsorted, flag;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i != n; i++) cin >> a[i];

	unsorted = 0;
	flag = 1;
	t = 0;
	while(flag){
		flag = 0;
		for (int j = n - 1; j != unsorted; j--){
			if (a[j - 1] > a[j]){
				dum = a[j - 1];
				a[j - 1] = a[j];
				a[j] = dum;
				flag = 1;
				t++;
			}
		}
		unsorted++;
	}

	for (int i = 0; i != n; i++) cout << (i == 0 ? "" : " ") << a[i];
	cout << endl << t << endl;
}
