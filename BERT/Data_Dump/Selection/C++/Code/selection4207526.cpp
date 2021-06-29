#include <iostream>
using namespace std;

int selection_sort(int A[], int n);
void trace(int A[], int n);

int main(int argc, char *argv[])
{
	int A[100];
	int n, sn;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	
	sn = selection_sort(A, n);
	trace(A, n);
	cout << sn << endl;
	return 0;
}


int selection_sort(int A[], int n)
{
	int sw = 0;
	for (int i = 0; i < n; i++)
	{
		int min = i;
		for (int j = i+1; j < n; j++)
		{
			if (A[j] < A[min])
				min = j;
		}
		if (min != i)
		{
	    	swap(A[i], A[min]);
    		sw++;		    
		}

	} 
	return sw;
} 

void trace(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (i) cout << ' ';
		cout << A[i]; 
	}
	cout << endl;
}
