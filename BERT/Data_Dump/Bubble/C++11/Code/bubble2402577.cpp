#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <numeric>
#include <ctype.h>
#include <cstdlib>
#include <string.h>
#include <cmath>
#include <cstdio>

using namespace std;

int main()
{
	int n, cnt = 0, input;
	vector<int> vec;
	bool flag = 1;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		vec.push_back(input);
	}

	while (flag)
	{
		flag = 0;
		for (int i = n - 1; i >= 1; i--)
		{
			if (vec[i] < vec[i - 1])
			{
				swap(vec[i], vec[i - 1]);
				flag = 1;
				cnt++;
			}
		}
	}

	int i = 0;

	for (auto a : vec)
	{
		cout << (i ? " " : "") << a;
		i++;
	}

	cout << endl;

	cout << cnt << endl;
}
