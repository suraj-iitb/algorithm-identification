#include <iostream>
using namespace std;
int main()
{
    int count, key;
    cin >> count;
    int A[count + 1];
    for (int i = 0; i < count; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < count; i++)
    {
        key = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
        for (int i = 0; i < count; i++)
        {
            if (i < count - 1)
                cout << A[i] << " ";
            else
                cout << A[i];
        }
        cout << endl;
    }

    return 0;
}
