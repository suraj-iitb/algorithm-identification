#include<iostream>

using namespace std;

int bubble_sort(int A[], int n)
{
    int sn = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = n-1; j > 0; j--)
        {
            if (A[j] < A[j-1])
            {
                swap(A[j], A[j-1]);
                sn++;
            }
        }
    }
    return sn;
}

void trace(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << ' ';
        cout << A[i];
    }
    cout << endl;
}
int main()
{
    int A[100];
    int n, sn;
    
    cin >> n;
    
    for (int i =0; i < n; i++)
        cin >> A[i];
    
    sn = bubble_sort(A, n);
    
    trace(A,n);
    cout << sn << endl;
}
