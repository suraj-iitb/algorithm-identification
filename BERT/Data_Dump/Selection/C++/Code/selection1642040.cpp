#include <iostream>
#include <utility>

using namespace std;

void output(int n, int element[])
{
	for (int i = 0; i < n - 1; i++)
		cout << element[i] << " ";
	cout << element[n - 1] << endl;
}

int selection_sort(int n, int element[])
{
	int swap_count = 0;
	for (int i = 0; i < n; i++) {
		int minimam = i;
		// select minimam element
		for (int j = i + 1; j < n; j++) {
			if (element[j] < element[minimam])
				minimam = j;
		}
//		output(n, element);
		if (minimam != i)
			swap(element[i], element[minimam]), swap_count++;
	}
	return swap_count;
}

int main()
{
	int n, element[100];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> element[i];
	}
	int swap_count = selection_sort(n, element);
	output(n, element);
	cout << swap_count << endl;
	return 0;
}
