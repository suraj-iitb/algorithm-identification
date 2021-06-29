#define _LIBCPP_DEBUG 0

#include <iostream>
#include <vector>

using namespace std;

int selectionSort(vector<int> A, int N)
{
    int minj;
    int count = 0;

    for (int i = 0; i < N-1; i++)
    {
        minj = i;
        for (int j = i; j < N; j++)
        {
            if (A.at(j) < A.at(minj))
            {
                minj = j;
            }
        }
        swap(A.at(i), A.at(minj));
        if (i != minj)
        {
            count++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (i > 0)
        {
            cout << " ";
        }
        cout << A.at(i);
    }
    cout << "\n";
    cout << count << "\n";
}

int main() {
    int N, i;
    cin >> N;

    vector<int> vec(N);

    for (i = 0; i < N; i++)
    {
        cin >> vec.at(i);
    }

    selectionSort(vec, N);
}

