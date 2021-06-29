#include <iostream>
#include <vector>
using namespace std;

void print_sort(vector<int> A)
{
    int i;
    int N = A.size();
    for (i = 0; i < N; ++i)
    {
        if (i == N - 1)
        {
            cout << A[i] << endl;
        }
        else
        {
            cout << A[i] << " " << flush;
        }
    }
}

void insertionSort(vector<int> A) // N個の要素を含む0-オリジンの配列A
{
    int i;
    int N = A.size();
    for (i = 1; i <= N; ++i)
    {
        print_sort(A);

        int v = A[i];
        int j = i - 1;

        while (j >= 0 && A[j] > v)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = v;
    }
}
int main()
{
    int N;
    vector<int> A;

    cin >> N;
    int i;
    A.reserve(N);
    for (i = 0; i < N; ++i)
    {
        int n;
        cin >> n;
        A.push_back(n);
    }
    insertionSort(A);
}
