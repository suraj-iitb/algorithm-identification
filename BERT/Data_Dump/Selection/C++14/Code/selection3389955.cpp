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

void selectionSort(vector<int>& intArray, int& swapCount)
{
	swapCount = 0;
	const int numberOfElements = intArray.size();
	for (int i = 0; i != numberOfElements - 1; ++i) {
		int minIndexJ = i;
		for (int j = i; j != numberOfElements; ++j) {
			if (intArray.at(j) < intArray.at(minIndexJ)) {
				minIndexJ = j;
			}
		}
		if (minIndexJ != i) {
			swap(intArray.at(i), intArray.at(minIndexJ));
			++swapCount;
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
	selectionSort(intArray, swapCount);
	const string values = accumulate(intArray.begin() + 1, intArray.end(), to_string(intArray.front())
		, [](const string& init, const int v) {return init + " " + to_string(v); });
	cout << values << endl;
	cout << swapCount << endl;

	return 0;
}
