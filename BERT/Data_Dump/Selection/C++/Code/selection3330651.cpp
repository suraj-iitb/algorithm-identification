#include<iostream>
#include<algorithm>
using namespace std;

static const int maxsize = 100;

void showSeq(int a[],int n) {
	for (int i = 0; i < n; i++) {
		if (i > 0)cout << " ";
		cout << a[i];
	}
	cout << endl;
}

int selectionSort(int a[],int n) {
	int swapCount = 0;
	for (int i = 0; i < n; i++) {
		int minValueIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (a[minValueIndex] > a[j])
				minValueIndex = j;
		}
		if (i != minValueIndex) {
           swap(a[i], a[minValueIndex]);
		   swapCount++;
		}		     		
	}
	return swapCount;
}


int main()
{
	
	int n, a[maxsize];
	cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	int count = selectionSort(a, n);
	showSeq(a,n);
	cout << count << endl;
    return 0;
}
