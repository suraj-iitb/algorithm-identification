// id: ALDS1_1_2_A
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::swap;

static const int MAX_N = 100;

int bubble_sort(int a[], int n);

int main()
{
	int arr[MAX_N];
	int n;
	int swap_times = 0;

	cin >> n;
	for ( int i = 0; i < n; ++i )
		cin >> arr[i];

	swap_times = bubble_sort(arr, n);

	cout << arr[0];
	for ( int i = 1; i < n; ++i )
		cout << " " << arr[i];
	cout << endl;

	cout << swap_times << endl;

	return 0;
}

int bubble_sort(int a[], int n)
{
	int cnt = 0;
	bool flag = true;
	int i = 0;

	while ( flag ) {
		flag = false;

		for ( int j = n - 1; j > i; --j )
			if ( a[j] < a[j - 1] ) {
				swap(a[j - 1], a[j]);
				++cnt;
				flag = true;
			}

		++i;
	}

	return cnt;
}
