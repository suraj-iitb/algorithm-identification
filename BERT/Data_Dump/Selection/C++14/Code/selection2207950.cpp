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

int selectionSort(int a[], int n)
{
    int count = 0;
    for(int i=0; i<n-1; i++)
    {
        int index = i;
        for(int j=i+1; j<n; j++)
        {
            if(a[j] < a[index])
                index = j;
        }
        if(index != i){
            count++;
            a[i] += a[index];
            a[index] = a[i] - a[index];
            a[i] = a[i] - a[index];
        }
    }
    return count;
}

int main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for(int i = 0; i < n; i++)
	{
	    cin >> a[i];
	}
	int sw = selectionSort(a, n);
	PrintfArray(a, n);
	cout << sw << endl;
	
	return 0;
}
