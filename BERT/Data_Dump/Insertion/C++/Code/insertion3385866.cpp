// ConsoleApplication.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdio.h"
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

static const int IntMax = 1000000000;

void outputA(const std::vector<int>& A)
{
	const int N = A.size();
	cout << A.front();
	for (int k = 1; k != N; ++k) {
		cout << " " << A.at(k);
	}
	cout << endl;
}

int main()
{
	//const int numberOfValues = getIntFromStringInput(cin);
	int N; cin >> N;
	std::vector<int> A(N);
	for (int k = 0; k != N; ++k) {
		cin >> A.at(k);
	}

	for (int i = 1; i != N; ++i) {
		outputA(A);
		int v = A.at(i);
		int j = i - 1;
		while (j >= 0 && A.at(j) > v) {
			A.at(j + 1) = A.at(j);
			--j;
		}
		A.at(j + 1) = v;
	}
	outputA(A);

	return 0;
}
