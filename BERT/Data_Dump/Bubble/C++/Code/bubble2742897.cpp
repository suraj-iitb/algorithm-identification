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

    //bubble sort
    int swp = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = N-1; j >= i+1; j--)
        {
            if (A[j] < A[j-1])
            {
                int tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                swp++;
            }
        }
    }
    
    trace(A,N);
    cout << swp << endl;
  
    return 0;
}

