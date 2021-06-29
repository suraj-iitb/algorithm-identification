#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];

	for (int j = 0; j < n-1; ++j)
			cout << a[j] << " ";
		cout << a[n-1] << endl;


	for (int i = 1; i < n; ++i)
	{
		int at = a[i];
		//atが初めてa[j]より大きくなんなかったときはa[dai]が最大
		int dai = i;

		//atの置き場所を考える
		for (int j = 0; j <= i-1; ++j)
		{
			//a[i]が初めてatより大きくなったとき
			if(at < a[j])
			{
				dai = j;
				break;
			}
		}
		//実際に配列に割り込んでatを置く
		for (int j = i; j > dai; --j)
			a[j] = a[j-1];
		a[dai] = at;
		for (int j = 0; j < n-1; ++j)
			cout << a[j] << " ";
		cout << a[n-1] << endl;
	}

	return 0;
}
