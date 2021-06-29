#include <iostream>
using namespace std;
static const int MAX = 100;

int bubbleSort(int A[], int N)
{
    int sw = 0;

    bool flag = 1;
    for (int i = 0; flag; i++)
    {
        flag = 0;
        for (int j = N - 1; j >= i + 1; j--)
        {
            if (A[j] < A[j - 1])
            {
                swap(A[j], A[j - 1]);
                flag = 1;
                sw++;
            }
        }
    }
    return sw;
};

int main()
{
    int A[MAX], j, N, sw;
    cin >> N;
    for (int k = 0; k < N; k++)
    {
        cin >> j;
        A[k] = j;
    }
    // int A[10] = {1, 6, 3, 7, 9, 423, 76, 432, 0, 64}, N = 10, sw;
    sw = bubbleSort(A, N);
    for (int i = 0; i < N; i++)
    {
        if (i)
        {
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
    cout << sw << endl;
    return 0;
}
