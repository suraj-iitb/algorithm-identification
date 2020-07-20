#include <iostream>
#include <vector>

void Print(int size, std::vector<int> ls) {
	for (int i = 0; i < size; i++)
		i != size - 1 ? std::cout << ls[i] << " " :
		std::cout << ls[i] << "\n";
}

void BubbleSort(int size, std::vector<int> ls) {
	int swap = 0;
	for (int i = 0; i < size; i++)
		for (int j = size - 1; j > 0; j--)
			if (ls[j] < ls[j - 1]) {
				int _ = ls[j];
				ls[j] = ls[j - 1];
				ls[j - 1] = _;
				swap++;
			}
	Print(size, ls);
	std::cout << swap << "\n";
}

std::vector<int> scan(int size) {
	std::vector<int> ls(size);
	for (int i = 0; i < size; i++) {
		std::cin >> ls[i];
	}
	return ls;
}

int main() {
	int size;
	std::cin >> size;
	BubbleSort(size, scan(size));
	return 0;
}

