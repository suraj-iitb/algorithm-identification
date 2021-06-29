#include <iostream>
#include <vector>
using namespace std;

int selectionSort(vector<int> &A, int N)
{
    int i, j, minj;
    int change_count = 0;
    for (i = 0; i < N; i++)
    {
        minj = i;
        for (j = i; j < N; j++)
        {
            if (A[j] < A[minj])
            {
                minj = j;
            }
        }
        if (i != minj)
        {
            swap(A[i], A[minj]);
            change_count++;
        }
    }
    return change_count;
}

int main()
{
    int N, i, change;
    cin >> N;
    vector<int> A(N);
    for (i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    change = selectionSort(A, N);
    cout << A[0];
    for (i = 1; i < N; i++)
    {
        cout << " " << A[i];
    }
    cout << "\n"
         << change << endl;
}
