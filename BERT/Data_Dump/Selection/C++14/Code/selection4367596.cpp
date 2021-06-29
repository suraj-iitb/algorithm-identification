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

void selectionSort(vector<int> vec, int len_vec)
{
    int swap_count = 0;
    for (int i = 0; i < len_vec; i++)
    {
        int min_ind = i;
        for (int j = i; j < len_vec; j++)
        {
            if (vec[min_ind] > vec[j])
            {
                min_ind = j;
            }
        }
        if (i != min_ind)
        {
            swap(vec[i], vec[min_ind]);
            swap_count++;
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
    selectionSort(A, N);
    return 0;
}
