#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void selectionSort(vector<int> &V, int N)
{
    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < N; j++)
        {
            if (V[j] < V[min_idx])
            {
                min_idx = j;
            }
        }

        if (min_idx != i)
        {
            cnt++;
            swap(V[i], V[min_idx]);
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << V[i];
        if (i != N - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    cout << cnt << endl;
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    selectionSort(A, N);

    return 0;
}
