// ConsoleApplication.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdio.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <vector>

using namespace std;

void bubbleSort(vector<int>& intArray, int& swapCount)
{
	swapCount = 0;
	bool existsInverseOrderElements = true;
	const int numberOfElements = intArray.size();
	while (existsInverseOrderElements) {
		existsInverseOrderElements = false;
		for (int i = numberOfElements - 1; i != 0; --i) {
			int& front = intArray.at(i - 1);
			int& back = intArray.at(i);
			if (front > back) {
				swap(front, back);
				++swapCount;
				existsInverseOrderElements = true;
			}
		}
	}
}

int main()
{
	int n;
	cin >> n;
	vector<int> intArray(n);
	for (auto& i : intArray) {
		cin >> i;
	}

	int swapCount;
	bubbleSort(intArray, swapCount);
	const string values = accumulate(intArray.begin() + 1, intArray.end(), to_string(intArray.front())
		, [](const string init, const int v) {return init + " " + to_string(v); });
	cout << values << endl;
	cout << swapCount << endl;

	return 0;
}
