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
	int count;

	cin >> count;

	int *s = new int[count];

	for (int f = 0; f < count; f++)
	{
		cin >> s[f];
	}

	for (int k = 0; k < count; k++)
	{
		cout << (k ? " " : "") << s[k];
	}

	cout << endl;

	

	for (int i = 1; i < count; i++)
	{
		int v = s[i];
		int j = i - 1;
		while (j >= 0 && s[j] > v)
		{
			s[j + 1] = s[j];
			j--;
		}

		s[j + 1] = v;

		for (int k = 0; k < count; k++)
		{
			cout << (k ? " " : "") << s[k];
		}

		cout << endl;
	}
}
