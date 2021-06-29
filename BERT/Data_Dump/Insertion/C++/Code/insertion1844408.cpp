#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <fstream>
#include <complex>
#include <math.h>
#include <ctype.h>
using namespace std;
int n,A[1000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for (int ii = 0; ii < n - 1; ii++)
	{
		cout << A[ii] << " ";
	}
	cout << A[n - 1] << endl;

	for (int i = 1; i < n; i++) {
		int v = A[i];
		int j = i - 1;
		while (j >= 0 && A[j] > v) {
			A[j + 1] = A[j];
				j--;
				A[j + 1] = v;
		}

		for (int ii = 0; ii < n - 1; ii++)
		{
			cout << A[ii] << " ";
		}
		cout << A[n - 1] << endl;
	}
	return 0;
}
