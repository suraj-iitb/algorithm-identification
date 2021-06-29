#include <iostream>
using namespace std;

int selectionSort(int A[], int n);

int main(void)
{
    int n, i;
    cin >> n;
    int *A = new int[n];
    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    
    int count = selectionSort(A, n);
    
    for (i = 0; i < n - 1; i ++)
    {
        cout << A[i] << " " ;
    }
    cout << A[i] << endl << count << endl;
}
int selectionSort(int A[], int n)
{
    int i, j, min, count = 0;
    for (i = 0; i < n; i++)
    {
        min = i;
        for  (j = i; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        if (min != i)
        {
            swap(A[i], A[min]);
            count++;
        }
    }
    return count;
}
