#include <iostream>
#include <utility>
using namespace std;
static const int NMAX = 100;
static const int VMAX = 100;

void show_vec(int n, int* vec) {
	for (int i = 0; i < n; i++) {
		if (i != 0) cout << " ";
		cout << vec[i];
	}
	cout << endl;
}

int bubbleSort(int n, int* vec) {
	bool flag = 1;
	int i = 0, num_sw = 0;
	while (flag) {
		flag = 0;
		for (int j = n - 1; j > i; j--) {
			if (vec[j - 1] > vec[j]) {
				swap(vec[j - 1], vec[j]);
				flag = 1;
				num_sw++;
			}
		}
		i++;
	}
	show_vec(n, vec);

	return num_sw;
}

int main() {
	int argc, argv[100], num_sw;

	cin >> argc;
	for (int i = 0; i < argc; i++) cin >> argv[i];

	//show_vec(argc, argv);
	num_sw = bubbleSort(argc, argv);

	cout << num_sw << endl;

	return 0;
}
