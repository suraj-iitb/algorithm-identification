#include <iostream>
using namespace std;
int main(void){
	int n;
	int ret[1000];
	int temp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ret[i];
	}
	for (int i = 0; i < n; i++) {
		temp = ret[i];
		int j = i - 1;
		while (j >= 0 && ret[j] > temp) {
			ret[j + 1] = ret[j];
			j--;
		}
		ret[j + 1] = temp;
		for (int k = 0; k < n; k++) {
			cout << ret[k];
			if (k != n - 1) {
				cout << " ";
			}
			else {
				cout << endl;
			}
		}
	}
}
