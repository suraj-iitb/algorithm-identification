#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
#define A

#ifdef A
int main(void)
{
	int cunt = 0;
	int n;
	cin >> n;
	list<int> arr(n);
	for (auto& a : arr)
		cin >> a;
	bool cont = true;
	while (cont)
	{
		list<int>::iterator it1 =arr.begin() ,it2 = arr.begin();
		advance(it2,1);
		cont = false;
		for (int i = 1; i < n; ++i, advance(it1,1), advance(it2,1))
		{
			if (*it1 > *it2) {
				swap(*it1, *it2);
				cont = true;
				cunt++;
			}

		}

	}
	list<int>::iterator it = arr.begin();
	cout << *it;
	advance(it, 1);
	for (; it !=arr.end(); advance(it,1))
		cout <<" "<< *it;
	cout << endl << cunt << endl;
	return 0;
}
#endif // A
