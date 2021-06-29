#include <iostream>
using namespace std;

int main()
{
    int A[100], N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++)
    {
        if (i > 0)
            cout << " ";
        cout << A[i];
    }
    cout << endl;

    for (int i = 1; i < N; i++)
    {
        int v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
        for (int i = 0; i < N; i++)
        {
            if (i > 0)
                cout << " ";
            cout << A[i];
        }
        cout << endl;
    }
}
