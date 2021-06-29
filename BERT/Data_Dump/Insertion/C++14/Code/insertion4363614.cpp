#include <iostream>
#include <vector>
using namespace std;
void out_vec(vector<int> vec, int len_vec)
{
    for (int i = 0; i < len_vec; i++)
    {
        cout << vec[i];
        if (i == len_vec - 1)
            cout << "\n";
        else
            cout << " ";
    }
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; i++)
    {
        int tmp_v = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > tmp_v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = tmp_v;
        out_vec(A, N);
    }
    return 0;
}
