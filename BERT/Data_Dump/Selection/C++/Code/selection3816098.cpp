#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];

    int counter = 0;
    for (int i = 0; i < N; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < N; j++)
        {
            if (A[j] < A[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(A[i], A[minIndex]);
            counter++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << counter << endl;
}

