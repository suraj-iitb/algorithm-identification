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

void bubbleSort(vector<int> vec, int len_vec)
{
    bool sort_flag = true;
    int swap_count = 0;
    while (sort_flag == true)
    {
        sort_flag = false;
        for (int i = len_vec - 1; i >= 1; i--)
        {
            if (vec[i] < vec[i - 1])
            {
                swap(vec[i], vec[i - 1]);
                sort_flag = true;
                swap_count++;
            }
        }
    }
    out_vec(vec, len_vec);
    cout << swap_count << "\n";
}

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    bubbleSort(A, N);
    return 0;
}
