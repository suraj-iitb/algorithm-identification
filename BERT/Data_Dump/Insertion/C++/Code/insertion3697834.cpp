#include <iostream>
using namespace std;
#define MAX 100
int A[MAX];
int main()
{
    int n, j;
    cin >> n;
    int key;
    for (int i = 0; i < n; i++)
    {
        cin >> j;
        A[i] = j;
    }

    for (int i = 0; i < n; i++)
    {
        key = A[i];
        j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
        if (i >= 0)
        {

            for (int j = 0; j < n; j++)
            {
                if (j)
                {
                    cout << " ";
                }
                cout << A[j];
            }
            cout << endl;
        }
    }
    return 0;
}
