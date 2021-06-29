#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
#define B

#ifdef B
int main(void)
{
	int n;
	cin >> n;
	list<int> arr(n);
	for (auto &a : arr)
		cin >> a;
	int cunt = 0;
	list<int>::iterator it1, it2,min, itend = arr.end();
	for (it1 = arr.begin(); it1 != itend; advance(it1,1))
	{
		min = it1;
		for (it2 = next(it1); it2 != itend; advance(it2, 1))
		{
			if (*it2 < *min)
				min = it2;
		}
		if (it1 != min) {
			cunt++;
			swap(*it1, *min);
		}

	}
	list<int>::iterator it = arr.begin();
	cout << *it;
	advance(it, 1);
	for (; it != arr.end(); advance(it, 1))
		cout << " " << *it;
	cout << endl << cunt << endl;



	return 0;
}
#endif // B
