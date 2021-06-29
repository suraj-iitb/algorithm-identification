#include <iostream>
#include <vector>
using namespace std;

template<typename Con>
auto printContainer(Con container) -> void
{
	for (int i = 0; i < container.size(); i++) {
		cout << container[i];
		if (i != container.size() - 1)
			cout << ' ';
	}
	cout << endl;
}

template<typename Con>
auto insertSort(Con container) -> void
{
	for (int i = 0; i < container.size(); i++) {
		auto key = container[i];
		int j = i - 1;
		while (j >= 0 && container[j] > key) {
			container[j + 1] = container[j];
			j--;
		}
		container[j + 1] = key;

		printContainer(container);
	}
}

auto main(void) -> int
{
	int nItemMax;
	cin >> nItemMax;
	vector<int> container;
	for (int nItem = 0; nItem < nItemMax; nItem++) {
		int n;
		cin >> n;
		container.push_back(n);
	}
	insertSort(container);

	return 0;
}
