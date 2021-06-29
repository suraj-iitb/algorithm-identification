#include <iostream>
using namespace std;

void bubbleSort(int A[], int n, int & count);

int main(void) 
{
    int n, i;
    cin >> n;
    int *A = new int[n];
    for (i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int count = 0;
    bubbleSort(A, n, count);
    
    for (i = 0; i < n - 1; i++)
        cout << A[i] << " ";
    cout << A[i] << endl << count << endl;
}

void bubbleSort(int A[], int n, int & count)
{
    int i = 0, j;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (j = n - 1; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                flag = true;
                swap(A[j], A[j - 1]);
                count++;
            }
        }
        i++;
    }
}
