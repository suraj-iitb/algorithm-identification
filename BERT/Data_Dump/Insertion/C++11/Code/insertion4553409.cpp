#include <cstdio>
#include <vector>

using namespace std;

int main() {
	vector <int> sequence;
	int number = 0;
	int size = 0;

	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &number);
		sequence.push_back(number);
	}
	for (int i = 0; i < size; i++) {
		int key = sequence[i];
		int j = i - 1;
		while (j >= 0 && sequence[j] > key) {
			number = sequence[j+1];
			sequence[j+1] = sequence[j];
			sequence[j] = number;
			j--;
		}
		for (int a = 0; a < size-1; a++) {
			printf("%d ", sequence[a]);
		}
		printf("%d\n", sequence[size-1]);
	}
}

