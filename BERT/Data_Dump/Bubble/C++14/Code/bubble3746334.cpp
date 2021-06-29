#include <iostream>
#include <vector>
using namespace std;

int cnt = 0;

void bubbleSort(vector<int> &V, int N)
{
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int i = N - 1; i > 0; i--)
        {
            if (V[i] < V[i - 1])
            {
                int tmp = V[i];
                V[i] = V[i - 1];
                V[i - 1] = tmp;
                flag = true;
                cnt++;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    bubbleSort(A, n);

    for (int i = 0; i < n; i++)
    {
        cout << A[i];
        if (i != n - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
    cout << cnt << endl;

    return 0;
}
