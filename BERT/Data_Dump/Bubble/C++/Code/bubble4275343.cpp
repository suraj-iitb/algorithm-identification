#include <iostream>
#include <vector>
using namespace std;

int bubbleSort(vector<int> *A, int N)
{
    int change_count = 0;
    bool flag = true;
    while (flag)
    {
        flag = false;
        for (int j = N - 1; j > 0; j--)
        {
            if (A->at(j) < A->at(j - 1))
            {
                swap(A->at(j), A->at(j - 1));
                flag = true;
                change_count++;
            }
        }
    }
    return change_count;
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
    int change = bubbleSort(&A, n);
    cout << A[0];
    for (int i = 1; i < n; i++)
    {
        cout << " " << A[i];
    }
    cout << "\n"
         << change << endl;
}

