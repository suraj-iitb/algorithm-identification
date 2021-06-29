#include <stdio.h>
#include <iostream>
using namespace std;

void insertionSort(int ary[], int num);
void outputArray(int ary[], int num);

int main(void)
{
	int n;
	cin >> n;
	
	int i = 0, a[100];
	while (cin >> a[i++]) {};
	
	insertionSort(a, n);
	
	return 0;
}

void insertionSort(int ary[], int num)
{
	outputArray(ary, num);
	
	int i;
	for (i = 1; i < num; i++) {
		int v = ary[i];
		int j = i - 1;
		while (j >= 0 && ary[j] > v) {
			ary[j+1] = ary[j];
			j--;
		}
		ary[j+1] = v;
		
		outputArray(ary, num);
	}
}

void outputArray(int ary[], int num)
{
	for(int i = 0; i < num - 1; i++){
		cout << ary[i] << " ";
	}
	cout << ary[num-1] << endl;
}
