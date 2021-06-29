#include <iostream>
#include <vector>

void Print(int size, std::vector<int> ls) {
	for (int i = 0; i < size; i++)
		i != size - 1 ? std::cout << ls[i] << " " :
		std::cout << ls[i] << "\n";
}

void SelectionSort(int size, std::vector<int> ls) {
	int swap = 0, mini;
	for (int i = 0; i < size; i++) {
		mini = i;
		for (int j = i; j < size; j++)
			if (ls[j] < ls[mini]) {
				mini = j;
			}
		if (i != mini) {
			int _ = ls[i];
			ls[i] = ls[mini];
			ls[mini] = _;
			swap++;
		}
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
	SelectionSort(size, scan(size));
	return 0;
}

