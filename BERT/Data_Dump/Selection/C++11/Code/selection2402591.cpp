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

	for (int i = 0; i < n; i++)
	{
		int minj = i;
		for (int j = i; j < n; j++)
		{
			if (vec[j] < vec[minj])
			{
				minj = j;
			}

				
		}
		swap(vec[i], vec[minj]);
		if (i != minj)
			cnt++;
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
