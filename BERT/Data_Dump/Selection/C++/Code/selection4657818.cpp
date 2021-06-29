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

int selection_sort(vector<int> &A, int N)
{
    int count = 0;
    for (int i = 0; i < N - 1; i++)
    {
        int minj = i;
        for (int j = i + 1; j < N; j++)
        {
            if (A.at(minj) > A.at(j))
            {
                minj = j;
            }
        }
        if (i != minj)
            count++;
        swap(A.at(i), A.at(minj));
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

    int count = selection_sort(A, N);

    print_vector(A, N);
    cout << count << endl;
}
