#include <iostream>
using namespace std;

void trace(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i > 0) cout << " ";
        cout << A[i];
    }
    cout << endl;
}

int main()
{
    int maxN = 1000;
    int A[maxN];

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    trace(A, N);

    //insertion sort
    for (int i = 1; i < N; i++)
    {
        int v = A[i];
        int j = i-1;
        while (j >= 0 && A[j] > v)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    
        trace(A, N);
    }
    
    return 0;
}
