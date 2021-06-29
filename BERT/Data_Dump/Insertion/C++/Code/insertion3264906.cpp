#include <iostream>

using namespace std;

const int n = 100;

int trace(int buf[], int sum)
{
	for(int i = 0; i < sum; i++) {
		if( i > 0 ) 
			cout << " ";
		cout << buf[i];
	}
	cout << endl;
	return 0;
}

void insertionSort(int buf[], int sum) 
{
	int i, j, key;
	for( i = 1; i < sum; i++) {
		j = i - 1;
		key = buf[i];
		while(j >= 0 && buf[j] > key) {
			buf[j+1] = buf[j];
			j--;
		}
		buf[j+1] = key;
		trace(buf, sum);
	}
}

int main()
{
	int buf[n];
	int sum = 0;
	cin >> sum;
	for(int i = 0; i < sum; i++)
		cin >> buf[i];
	trace(buf, sum);
	insertionSort(buf, sum);
	return 0;
}
