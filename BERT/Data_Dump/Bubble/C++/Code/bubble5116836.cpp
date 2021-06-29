#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	int n;
	cin >> n;

	int R[200], tmp;
	int count = 0;
	for (int i = 0; i<n; i++) {
		cin >> R[i];
	}

	

	for (int i = 0; i < n - 1; i++) {
		for (int j = n - 1; j > i; j--) {
			if (R[j - 1] > R[j]) {
				tmp = R[j - 1];
				R[j - 1] = R[j];
				R[j] = tmp;
				count++;
			}
		}
	}

	for (int i = 0; i <n; i++) {
		cout << R[i];
		if(i!=n-1){
		    cout <<" ";
		}
	}
	cout << endl;
	cout << count << endl;

	return 0;
}
