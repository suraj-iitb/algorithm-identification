#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    int v, j;

    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }

    for (int i = 0; i < N; i++)
    {
        cout << A.at(i);
        if (i != N - 1)
            cout << " ";
    }
    cout << endl;

    for (int i = 1; i < N; i++)
    {
        v = A.at(i);
        j = i - 1;
        while (j >= 0 && A.at(j) > v)
        {
            A.at(j + 1) = A.at(j);
            j--;
            A.at(j + 1) = v;
        }

        for (int j = 0; j < N; j++)
        {
            cout << A.at(j);
            if (j < N - 1)
                cout << " ";
            if (j == N - 1)
                cout << endl;
        }
    }
}
