#include <iostream>
using namespace std;

void PrintfArray(int a[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if( i )
            cout << " ";
        cout << a[i];
    }
    cout << endl;
}

void insertionSort(int a[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while(j >= 0 && temp < a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
        PrintfArray(a, n);
    }
}

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for(int i = 0; i < n; i++)
	{
	    cin >> a[i];
	}
	
	PrintfArray(a, n);
	
	insertionSort(a, n);
	
	
	return 0;
}
