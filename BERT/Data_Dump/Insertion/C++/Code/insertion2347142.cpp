#include <iostream>
using namespace std;
int main(void)
{
    int N, A[100], key, i, j, k;
    cin >> N;
    for (i = 0; i < N; i++)
        cin >> A[i];
    for (i = 0; i < N; i++)
    {
        cout << A[i];
        if (i < N-1)
            cout << " ";
        else
            cout << endl;
    }
    for (j = 1; j < N; j++)
    {
        key = A[j];
        i = j-1;
        while (i >= 0 && A[i] > key)
        {
            A[i+1] = A[i];
            i--;
        }
        A[i+1] = key;
        for (k = 0; k < N; k++)
        {
            cout << A[k];
            if (k < N-1)
                cout << " ";
            else
                cout << endl;
        }
    }
    return 0;
}
