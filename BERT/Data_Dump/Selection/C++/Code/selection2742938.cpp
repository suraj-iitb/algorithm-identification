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

    //selection sort
    int swp = 0;
    for (int i = 0; i < N; i++)
    {
        int mini = i;
        for (int j = i; j < N; j++)
        {
            if (A[j] < A[mini])
            {
                mini = j;
            }
        }
        
        if (mini != i)
        {
            int tmp = A[i];
            A[i] = A[mini];
            A[mini] = tmp;
            swp++;
        }
    }
    
    trace(A,N);
    cout << swp << endl;
  
    return 0;
}

