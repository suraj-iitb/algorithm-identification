#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int bubblesort(vector<int> &A, int N)
{
    int cnt = 0;

    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int j = N - 1; j > 0; j--)
        {
            if (A.at(j) < A.at(j - 1))
            {
                swap(A.at(j), A.at(j - 1));
                cnt++;
                flag = true;
            }
        }
    }
    return cnt;
}
int main()
{
    int N;
    cin >> N;

    vector<int> A(N);
    int n;
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i);
    }

    int cnt = bubblesort(A, N);

    for (int i = 0; i < A.size() - 1; i++)
    {
        cout << *(A.begin() + i) << ' ';
    }
    cout << A.back() << endl;

    cout << cnt << endl;
}
