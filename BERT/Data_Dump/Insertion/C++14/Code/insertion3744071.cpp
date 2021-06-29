#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> &V, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << V[i];
        if (i != N - 1)
        {
            cout << " ";
        }
    }
    cout << endl;

    for (int i = 1; i < N; i++)
    {
        int v = V[i];
        int j = i - 1;
        while (j >= 0 && V[j] > v)
        {
            V[j + 1] = V[j];
            j--;
        }
        V[j + 1] = v;

        for (int k = 0; k < N; k++)
        {
            cout << V[k];
            if (k != N - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    insertionSort(A, n);

    return 0;
}
