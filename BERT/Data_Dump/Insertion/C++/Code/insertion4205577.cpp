#include<iostream>

using namespace std;

int MAX = 100;

void trace(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << ' ';
        cout << A[i];
    }
    cout << endl;
}


void insertion_sort(int A[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = A[i], j = i - 1;
        while (j >= 0 && key < A[j])
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
        trace(A, n);
    }
}

int main()
{
    int A[MAX], n;
    
    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> A[i];

    trace(A, n);
    
    insertion_sort(A, n);
    
    return 0;
}
