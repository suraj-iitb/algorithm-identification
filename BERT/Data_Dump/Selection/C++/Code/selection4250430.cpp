#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int selectionSort(vector<int> &A)
{
    int cnt = 0;
    for (std::vector<int>::size_type i = 0; i < A.size(); i++)
    {
        std::vector<int>::size_type minj = i;
        for (std::vector<int>::size_type j = i; j < A.size(); j++)
        {
            if (A.at(j) < A.at(minj))
            {
                minj = j;
            }
        }
        if (i != minj)
        {
            cnt++;
            swap(A.at(i), A.at(minj));
        }
    }
    return cnt;
}
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }

    int cnt = selectionSort(A);

    for (std::vector<int>::size_type i = 0; i < A.size() - 1; i++)
    {
        cout << A.at(i) << ' ';
    }
    cout << A.back() << endl;

    cout << cnt << endl;
}
