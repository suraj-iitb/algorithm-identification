#include <iostream>
#include <vector>

using namespace std;

int bubbleSort(vector<int> &A);

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A)
        cin >> x;

    int count = bubbleSort(A);
    for (int i = 0; i < A.size(); i++)
    {
        i ? cout << " " << A[i] : cout << A[i];
    }
    cout << endl
         << count << endl;
}

int bubbleSort(vector<int> &A)
{
    int count = 0;

    for (int i = 0; i < A.size() - 1; i++)
    {
        for (int j = A.size() - 1; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                int tmp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = tmp;
                count++;
            }
        }
    }

    return count;
}

