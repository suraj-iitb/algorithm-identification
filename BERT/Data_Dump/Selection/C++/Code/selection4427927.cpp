#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    int cnt = 0;
    cin >> N;
    int A[N];
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for(int i = 0; i < N; i++)
    {
        int minj = i;
        for(int j = i; j < N; j++)
        {
            if(A[minj] > A[j])
                minj = j;
        }
        if(minj != i)
            cnt++;
        swap(A[i], A[minj]);
    }
    for(int i = 0; i < N; i++)
    {
        if(i > 0)
            cout << " ";
        cout << A[i];
    }
    cout << endl;
    cout << cnt << endl;
    return 0;
}

