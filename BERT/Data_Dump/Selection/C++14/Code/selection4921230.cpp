#include <iostream>
#include <vector>

using namespace std;

int selectionSort(vector<int> &A);

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (auto &x : A)
        cin >> x;

    int count = selectionSort(A);
    for (int i = 0; i < A.size(); i++)
    {
        i ? cout << " " << A[i] : cout << A[i];
    }
    cout << endl
         << count << endl;
}

int selectionSort(vector<int> &A)
{
    int count{};
    for (int i = 0; i < A.size(); i++)
    {
        int minj = i;
        for (int j = i; j < A.size(); j++)
        {
            if (A[j] < A[minj])
                minj = j;
        }
        if (i != minj)
        {
            swap(A[i], A[minj]);
            count++;
        }
    }
    return count;
}

