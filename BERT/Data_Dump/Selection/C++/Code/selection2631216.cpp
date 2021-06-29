#include <iostream>
#include <utility>
using namespace std;
static int const NUM_MAX = 100;
static int const VAL_MAX = 100;

void show_argv(int argc, int argv[]) {
	for (int i = 0; i < argc; i++) {
		if (i != 0) cout << " ";
		cout << argv[i];
	}
	cout << endl;
}

void selectionSort(int argc, int argv[]) {
	int minj, sw_count = 0;
	for (int i = 0; i < argc; i++) {
		minj = i;
		for (int j = i + 1; j < argc; j++) {
			if (argv[j] < argv[minj]) minj = j;
		}
		if (minj != i) {
			swap(argv[i], argv[minj]);
			sw_count++;
		}
	}
	show_argv(argc, argv);
	cout << sw_count << endl;
}

int main() {
	int argc, argv[NUM_MAX];
	
	cin >> argc;
	for (int i = 0; i < argc; i++) cin >> argv[i];

	selectionSort(argc, argv);
}
