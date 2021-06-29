#include <iostream>
#include <list>
#include<vector>
#include <utility>
using namespace std;

#define A

#ifdef A
void fucPri(list<int> &ori) {
	list<int>::iterator iend = ori.end();
	list<int>::iterator i = ori.begin();
	cout << *i++;
	for (; i != iend; ++i)
	{
		cout << " "<< *i;
	}
	cout << endl;
}
int main(void)
{
	int n;
	cin >> n;
	list<int> ori(n);
	for (auto &a : ori)
	{
		cin >> a;
	}
	for (size_t i = 0; i < n; i++)
	{
		list<int>::iterator it = ori.begin();
		advance(it, i);
		int v = *(it);
		ori.erase(it);
		it = ori.begin();
		for (size_t j = 0; j < i; ++j,advance(it, 1))
		{
			if (*it > v)
				break;
		}

		ori.insert(it, v);
		fucPri(ori);

	}
	

	return 0;
}
#endif // A
