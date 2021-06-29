#include <cstdio>
#include <vector>

using namespace std;

int main() {
	vector <int> list;
	int swaps = 0;
	int size = 0;
	int num = 0;

	scanf("%d", &size);
	for (int i = 0; i < size; i++) {
		scanf("%d", &num);
		list.push_back(num);
	}
	size = size-1;
	for (int i = 0; i <= size; i++) {
		num = i;
		for (int j = i; j <= size; j++) {
			if (list[j] < list[num]) {
				num = j;
			}
		}
		if (i != num) {
			list[i] = list[i] + list[num];
			list[num] = list[i] - list[num];
			list[i] = list[i] - list[num];
			swaps++;
		}
	}
	for (int i = 0; i < size; i++) {
		printf("%d ", list[i]);
	}
	printf("%d\n%d\n", list.back(), swaps);
}

