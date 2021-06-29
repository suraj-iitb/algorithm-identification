#include <vector>
#include <iostream>
using namespace std;

void insertionSort(int A[], int n);
void printArray(int A[], int n);

int main(void)
{
    int n, i;
    cin >> n;
    int *A = new int[n];
    for (i = 0; i < n; i++)
        cin >> A[i];
    
    insertionSort(A, n);
    
}

void insertionSort(int A[], int n)
{
    int i, j, v;
    for (i = 0; i < n; i++) 
    {
        v = A[i];
        for (j = i - 1; j >= 0 && A[j] > v; j--)
        {
            A[j + 1] = A[j];
        }
        A[j + 1] = v;
        printArray(A, n);
    }
}

void printArray(int A[], int n)
{
    int i;
    for (i = 0; i < n - 1; i++)
        cout << A[i] << " ";
    cout << A[i] << endl;
}
