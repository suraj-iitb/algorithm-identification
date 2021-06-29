#include <iostream>

using namespace std;

void insertionSort(int *A, int n)
{
    for(int i = 0; i < n; ++i)
    {
        int v = A[i];
        int j = i - 1;
        
        while( j >= 0 && A[j] > v)
        {
            A[j+1] = A[j];
          --j;
        }
        A[j + 1] = v;
        
        for(int k = 0; k < n - 1; ++k)
        { cout << A[k] << " "; }
        cout << A[n - 1] << endl;
    }
    return;
}

int main()
{
    int n;
    cin >> n;
    
    int A[n];
    
    for(int i = 0; i < n; ++i)
    { cin >> A[i]; }
    
    insertionSort(A, n);
    
    return 0;
}
