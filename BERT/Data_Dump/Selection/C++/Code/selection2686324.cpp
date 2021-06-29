#include<iostream>
#include<algorithm>
using namespace std;
void selectionSort()
{
    int A[100];
    int N;
    cin >> N;
 
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int m = i;
        for (int j = i + 1; j < N; j++)
        {
            if (A[m] > A[j])
            {
                m = j;
            }
        }
 
        if (m != i)
        {
            int temp = A[i];
            A[i] = A[m];
            A[m] = temp;
            ans++;
        }
    }
 
    for (int i = 0; i < N; i++)
    {
        if (i != N - 1)
        {
            cout << A[i] << " " << flush;
            continue;
        }
        else
        {
            cout << A[i] << endl;
        }
    }
 
    cout << ans << endl;
}
 
int main()
{
    selectionSort();
    return 0;
}
