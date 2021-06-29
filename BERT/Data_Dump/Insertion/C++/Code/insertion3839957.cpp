#include <iostream>
#include <vector>

int main() {
	int i, x;
	std::cin >> i;
	std::vector<int> ls(i);

	while (i != 0 && std::cin >> x) {
		ls[ls.size() - i] = x;
		i--;
	}
	for (int k = 1; k < ls.size(); k++) {
		int key = ls[k], j = k - 1;
		for (int i = 0; i < ls.size(); i++)
			i == ls.size() - 1 ?
			std::cout << ls[i] << "\n" :
			std::cout << ls[i] << " ";
		while (j >= 0 && ls[j] > key) {
			ls[j + 1] = ls[j];
			j--;
		}
		ls[j + 1] = key;
	}
	for (int i = 0; i < ls.size(); i++)
		i == ls.size() - 1 ?
		std::cout << ls[i] << "\n" :
		std::cout << ls[i] << " ";
	return 0;
}
