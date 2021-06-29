#include <iostream>

using namespace std;

int selectionSort(int buf[], int n)
{
	int index, i, j, sw = 0;
	for(i = 0; i < n; i++) {
		index = i;
		for(j = i + 1; j < n; j++) {
			if(buf[j] < buf[index]) {
				index = j;
			}
		}
		swap(buf[i],buf[index]);
		if(i != index)
			sw++;
	}
	return sw;
}

int main()
{
	int buf[100], n, sw;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> buf[i];
	sw = selectionSort(buf, n);

	for(int i = 0; i < n; i++) {
		if(i > 0) cout << " ";
		cout << buf[i];
	}
	cout << endl;
	cout << sw << endl;
	return 0;
}

