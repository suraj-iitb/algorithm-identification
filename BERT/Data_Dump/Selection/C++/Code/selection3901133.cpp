#include <iostream>
#include <vector>

using namespace std;

vector<int> A;
int n, minn, count = 0;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void SelectionSort()
{
    for (int i = 0; i < n; i++)
    {
        minn = i;
        for (int j = i; j < n; j++)
        {
            if (A[j] < A[minn])
            {
                minn = j;
            }
        }
        if (A[i] != A[minn])
        {
            swap(A[i], A[minn]);
            count++;
        }
    }
}

int main(int argc, const char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    A.resize(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    SelectionSort();

    for (int i = 0; i < n; i++)
    {
        cout << A[i];
        if (i < n - 1)
            cout << " ";
    }
    cout << "\n" << count << "\n";
    return 0;
}
