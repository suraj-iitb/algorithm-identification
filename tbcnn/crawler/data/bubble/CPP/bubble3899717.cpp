#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int count, temp = 0;
    cin >> count;
    int A[count + 1];
    for (int i = 0; i < count; i++)
    {
        cin >> A[i];
    }

    for (int i = 0; i < count; i++)
        for (int j = count - 1; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
                temp++;
            }
        }
    for (int i = 0; i < count; i++)
    {
        if (i < count - 1)
            cout << A[i] << " ";
        else
            cout << A[i];
    }
    cout << endl;
    cout << temp << endl;
    return 0;
}
