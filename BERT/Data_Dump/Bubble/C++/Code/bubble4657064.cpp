#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> A, int N)
{
    for (int i = 0; i < N; i++)
    {
        cout << A.at(i);
        if (i != N - 1)
            cout << " ";
    }
    cout << endl;
}

int bubble_sort(vector<int> &A, int N)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = N - 1; j >= i + 1; j--)
        {
            if (A.at(j - 1) > A.at(j))
            {
                count++;
                swap(A.at(j), A.at(j - 1));
            }
        }
    }
    return count;
}

int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A.at(i);

    int count = bubble_sort(A, N);

    print_vector(A, N);
    cout << count << endl;
}
