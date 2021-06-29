//insertion sort
#include <iostream>
#define max_n 101

using namespace std;

void trace(int* a, int n)
{
	for(int i = 0; i < n; ++i)
	{
		if(i > 0)
			cout << " ";
		cout << a[i];	
	}
	cout << endl;	
}

//in ascending order
void insertionSort(int* a, int n) 
{
	int key;
	for(int i = 1; i < n; i++)
    {
    	key = a[i];
    	int j = i - 1;
    	while(j >= 0 && a[j] > key)
    	{
    		a[j + 1] = a[j];
    		--j;      //j = 1 is possible
		}
		a[j + 1] = key;
		trace(a, n);
	}
}

int main(void)
{
	int n, a[max_n];
	
	cin >> n;
	for(int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}
	
	trace(a, n);
	insertionSort(a, n);
	
	return 0;
}
